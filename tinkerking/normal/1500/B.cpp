#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
LL k;
int a[1000010], b[1000010];
int pa[1000010], pb[1000010];

LL exgcd(LL a, LL b, LL &x, LL &y){
	if (!b)
		return x = 1, y = 0, a;
	LL d = exgcd(b, a % b, x, y), t = x;
	y = t - (a / b) * (x = y);
	return d;
}

inline LL mod(LL x, LL y){ // y > 0
	return (x %= y) < 0 ? x + y : x;
}

LL solve(int n, LL m[], LL c[]){
	for (int i = 0; i < n; i++)
		if (c[i] >= m[i]) return -1;
	LL ans = c[0], LCM = m[0], x, y, g;
	for (int i = 1; i < n; i++){
		if (LCM < m[i]) // m[i]int
			swap(LCM, m[i]), swap(ans, c[i]);
		g = exgcd(LCM, m[i], x, y);
		if ((c[i] - ans) % g) return -1;
		ans += LCM * mod((c[i] - ans) / g * x, m[i] / g);
		ans %= LCM *= m[i] / g;
	}
	return ans;
}

vector<LL> fuck;
LL MOD[2];
LL REMAIN[2];

int main() {
    scanf("%d%d%lld",&n,&m,&k);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<m;i++) {
        scanf("%d",&b[i]);
    }
    if (n > m) {
        swap(n, m);
        assert(m >= n);
        for (int i=0;i<m;i++) swap(a[i], b[i]);
    }
    for (int i=1;i<=1000000;i++) pa[i] = pb[i] = -1;
    for (int i=0;i<m;i++) {
        //printf("ma[%d] =  mb[%d] = %d\n",a[i],b[i],i);
        pa[a[i]] = i;
        pb[b[i]] = i;
    }
    LL lcm = 1LL * n * m / __gcd(n, m);
    for (int i=1;i<=1000000;i++) {
        if (pa[i] != -1 && pb[i] != -1) {
            int ma = pa[i], mb = pb[i];
            //printf("solve %d %d\n",ma,mb);
            MOD[0] = n;
            MOD[1] = m;
            REMAIN[0] = ma;
            REMAIN[1] = mb;
            LL ret = solve(2, MOD, REMAIN);
            if (ret == -1) continue;
            fuck.push_back(ret);
        }
    }
    k--;
    LL ans = k / (lcm - fuck.size()) * lcm;
    k %= (lcm - fuck.size());
    k++;
    sort(fuck.begin(), fuck.end());
    fuck.push_back(lcm);
    for (int i=0;i<fuck.size();i++) {
        if (fuck[i] - i >= k) {
            ans += (k + i);
            break;
        }
    }
    printf("%lld\n",ans);
}