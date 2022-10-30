//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

//const int N = (int)1e5 + 5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll la, ra, ta;
	ll lb, rb, tb;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	ll g = __gcd(ta, tb);
	ll ans = 0;
	ll A = la - lb;
	A %= tb;
	if(A < 0)A += tb;
	ll d = (tb - A);
	d = (d + g - 1)/g;
	A = A + d * g;
	A %= tb;
	ll cu = min(ra - la + 1, rb - lb + 1 - A);
	ans = max(ans, cu);
	swap(la, lb); swap(ra, rb); swap(ta,tb);
	A = la - lb;
	A %= tb;
	if(A < 0)A += tb;
	d = (tb - A);
	d = (d + g - 1)/g;
	A = A + d * g;
	A %= tb;
	cu = min(ra - la + 1, rb - lb + 1 - A);
	ans = max(ans, cu);
	cout << ans;
	return 0;
}