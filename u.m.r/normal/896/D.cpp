#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;

int n, m;

void prework(){
	
}

void read(){

}

//int f[1000][1000];

ll A[MAXN][11], B[MAXN][11], C[MAXN][11];

ll P;

vector<PII> pm;

ll pw(ll p, ll q, ll MM){
	ll ret = 1;
	p %= MM;
	for (; q; q >>= 1){
		if (q & 1)
			ret = ret * p % MM;
		p = p * p % MM;
	}
	return ret;
}

void nico(int n){
	int mod = P;
	for (ll i = 2; i * i <= mod; i++){
		if (mod % i == 0){
			int cnt = 0;
			while(mod % i == 0){
				mod /= i;
				cnt++;
			}
			pm.push_back(PII(i, cnt));
		}
	}
	if (mod != 1){
		pm.push_back(PII(mod, 1));
	}
	for (int i = 0; i < pm.size(); i++){
		int x = pm[i].first;
		int xx = 1;
		for (int j = pm[i].second; j >= 1; j--)
			xx *= x;
		/*
		xx = xx / x * (x - 1);
		xx--;*/
		int yy = xx / x * (x - 1) - 1;
		A[0][i] = 1;
		B[0][i] = 0;
		C[0][i] = 1;
		for (int j = 1; j <= n; j++){
			int y = j, z = 0;
			while(y % x == 0){
				z++; y/=x;
			}
			A[j][i] = y % xx;
			B[j][i] = z;
		}
		/*cout << "+++++++++++" << endl;
		for (int j = 0; j <= n; j++)
			cout << A[j][i] << ' ' << B[j][i] << endl;
		*/for (int j = 2; j <= n; j++){
			A[j][i] = A[j-1][i] * A[j][i] % xx;
			B[j][i] += B[j-1][i];
		}
		for (int j = 0; j <= n; j++){
			C[j][i] = pw(A[j][i], yy, xx);
		}
		/*cout << "------------" << endl;
		cout << x << ' ' << xx << ' ' << yy << endl;
		for (int j = 0; j <= n; j++)
			cout << A[j][i] << ' ' << B[j][i] << ' ' << C[j][i] << endl;
		*/
	}
}

ll crt_m[100], crt_c[100];

ll exgcd(ll a, ll b, ll &x, ll &y){
    if (!b)
        return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, x, y), t = x;
    y = t - (a / b) * (x = y);
    return d;
}

inline ll mod(ll x, ll y){ // y > 0
    return (x %= y) < 0 ? x + y : x;
}

ll crt_solve(int n, ll m[], ll c[]){
    for (int i = 0; i < n; i++)
        if (c[i] >= m[i]) return -1;
    ll ans = c[0], LCM = m[0], x, y, g;
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

ll CC(ll n, ll m){
	/*
	ll ans = 1;
	for (int i = 0; i < m; i++)
		ans *= (n - i);
	for (int i = 1; i <= m; i++)
		ans /= i;
	return ans % P;*/
	ll ans = 1;
	if (n < m || n < 0 || m < 0) return 0;
	for (int i = 0; i < pm.size(); i++){
		int x = pm[i].first;
		int cnt = pm[i].second;
		ll xx = 1;
		for (int j = 1; j <= cnt; j++) xx *= x;
		ll ret = A[n][i] * C[m][i] % xx * C[n - m][i] % xx;
		int maki = B[n][i] - B[m][i] - B[n-m][i];
		crt_m[i] = xx;
		if (maki >= cnt)
			crt_c[i] = 0;
		else{
			for (int j = 1; j <= maki; j++)
				ret = ret * x % xx;
			crt_c[i] = ret;
		}
	}
	ans = crt_solve(pm.size(), crt_m, crt_c);
	//cout << n << ' ' << m << ' ' << ans << endl;
	return ans;
}

ll gao(int n, int k){
	ll ret = 0;
	for (int j = 0; j <= n; j++){
		ret = (ret + CC(n, j) * CC(n - j, j + k)) % P;
	}
	return ret;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
/*	
	f[0][0] = 1;
	int n = 10;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++){
			for (int k = -1; k <= 1; k++)
				if (j + k >= 0)
					f[i][j] += f[i - 1][j + k];
		}
		cout << i << " :  " ;
		for (int j = 0; j <= i; j++)
			cout << f[i][j] << ' '; cout << endl;
	}*/
	int l, r;
	scanf("%d%d%d%d", &n, &P, &l, &r);
	if (P == 1){
		puts("0");
		return ;
	}
	nico(n);
	ll ans;
	ans = gao(n, l) + gao(n, l + 1) - gao(n, r + 1) - gao(n, r + 2);
	ans = (ans % P) + P;
	printf("%lld\n", ans % P);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}