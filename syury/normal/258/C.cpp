#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;
typedef long long int ll;
typedef long double dbl;
typedef unsigned long long uli;
typedef pair<int, int> pii;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i < r; i++)
#define DF(i, l, r) for(int i = l; i > r; i--)
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

const int MAXN = 1e5 + 5;
const int mod = 1000000007;

int n;
int a[MAXN];
int divs[MAXN];
ll ans = 0;

ll pw(ll a, int p){
	ll res = 1;
	while(p){
		if(p&1)res = (res * a)%mod;
		a = a * a % mod;
		p >>= 1;
	}
	ret res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n)cin >> a[i];
	sort(a, a + n);
	for(int x = 1; x <= a[n - 1]; x++){
		int sz = 0;
		for(int i = 1; i * i <= x; i++){
			if(x%i != 0)cont;
			divs[sz++] = i;
			if(i * i != x)divs[sz++] = x/i;
		}
		sort(divs, divs + sz);
		ll kurwa = 1;
		int was = 0, prv = n;
		for(int j = 0; j < sz; j++){
			int d = divs[j];
			int cnt = (a + n) - lower_bound(a, a + n, d);
			kurwa *= pw(was, prv - cnt);
			was++; prv = cnt;
			kurwa %= mod;
			if(d != x)cont;
			ll kek = (pw(was, cnt) - pw(was - 1, cnt))%mod;
			if(kek < 0)kek += mod;
			kurwa *= kek;
			kurwa %= mod;
		}
		ans = (ans + kurwa)%mod;
	}
	cout << ans;
	return 0;
}