#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int mod = (int)1e9 + 7;
const int MAXN = 1e5 + 5;

int n;
int pw[MAXN];
map<int, int> cnt;

int mu(int x){
	int ans = 1;
	int cu = x;
	for(ll i = 2; i * i <= x; i++){
		if(cu%i != 0)cont;
		if((cu/i)%i == 0)ret 0;
		cu /= i;
		ans *= -1;
	}
	if(cu != 1)ans *= -1;
	ret ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	pw[0] = 1;
	F(i, 1, MAXN)pw[i] = (pw[i - 1] + pw[i - 1])%mod;
	scanf("%d", &n);
	F(i, 0, n){
		int x;
		scanf("%d", &x);
		for(ll i = 1; i * i <= x; i++){
			if(x%i != 0)cont;
			cnt[i]++;
			if(i * i != x)cnt[x/i]++;
		}
	}
	ll ans = 0;
	F(i, 1, MAXN)ans += mu(i) * 1ll * (pw[cnt[i]] - 1)%mod;
	ans %= mod;
	ans = (ans + mod)%mod;
	printf("%lld", ans);
	ret 0;
}