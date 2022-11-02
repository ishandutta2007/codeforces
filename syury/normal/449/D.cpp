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
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

const int MAXN = 1e6;
const int mod = 1000000007;

int pw[MAXN + 3], f[MAXN + 2];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n){int x; scanf("%d", &x); f[x]++;}
	pw[0] = 1;
	F(i, 1, MAXN + 3)pw[i] = (pw[i - 1] * 2)%mod;
	F(j, 0, 20){
		Df(i, MAXN, -1){
			if(i&(1 << j))f[i - (1 << j)] = (f[i - (1 << j)] + f[i])%mod;
		}	
	}
	lint ans = 0;
	Df(i, MAXN, -1){
		int d = 1;
		if(__builtin_popcount(i)&1)d = -1;
		ans += d * 1ll * (pw[f[i]] - 1);
		ans %= mod;
	}
	if(ans < mod)ans += mod;
	ans %= mod;
	printf("%lld", ans);
	ret 0;
}