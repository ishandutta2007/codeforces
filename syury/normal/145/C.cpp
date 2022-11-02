#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define y1 adjf
#define ws wejgnjn
#define left fhgfj

const lint mod = 1000000007;
const int MAXN = 1e5 + 10;
const int MAXC = 2e3;

int n, k;
int a[MAXN];
lint dp[MAXC][MAXC];
lint psum[MAXC][MAXC];
lint cnt[MAXC];
lint fac[MAXN];

lint gcdex(lint a, lint b, lint & x, lint & y){
	if(a == 0){
		x = 0; y = 1; ret b;
	}	
	lint x1, y1, g;
	g = gcdex(b % a, a, x1, y1);
	y = x1;
	x = y1 - x1 * (b/a);
	ret g;
}

lint inv(lint a){
	lint x, y;
	gcdex(a, mod, x, y);
	x = (x % mod + mod)%mod;
	ret x;
}

lint C(lint n, lint k){
	if(n < k)ret 0ll;
	ret fac[n] * inv(fac[k] * fac[n - k] % mod) % mod;
}

bool good(int c){
	while(c){
		if(c % 10 != 4 && c % 10 != 7)ret false;
		c /= 10;
	}
	ret true;
}

map<int, int> id;
int cid = 0;
int bad = 0;

int main(){
	scanf("%d%d", &n, &k);
	F(i, 0, n){
		scanf("%d", &a[i]);
		if(!good(a[i])){bad++; cont;}
		if(!id.count(a[i]))id[a[i]] = cid++;
		cnt[id[a[i]]]++;
	}
	lint ans = 0ll;
	fac[0] = 1ll;
	F(i, 1, n + 1)
		fac[i] = fac[i - 1] * i % mod;
	if(bad >= k)ans = C(bad, k);
	F(i, 1, cid + 1){
		F(j, 0, cid){
			if(i == 1){dp[i][j] = cnt[j]; psum[i][j] = (dp[i][j] + ((j == 0) ? 0 : psum[i][j - 1]))%mod; cont;} 
			if(j >= i - 1)
				dp[i][j] = cnt[j] * 1ll * psum[i - 1][j - 1] % mod;
			else dp[i][j] = 0ll;
			psum[i][j] = ((j == 0) ? 0 : psum[i][j - 1]) + dp[i][j];
			if(psum[i][j] > mod)psum[i][j] -= mod;
		}
		if(k >= i)ans += psum[i][cid - 1] * C(bad, k - i) % mod;
		if(ans > mod)ans -= mod;
	}
	printf("%lld", ans % mod);
	ret 0;
}