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

const int N = (int)1e5 + 5;

int n, m, l;
ll a[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> l;
	F(i, 0, n)cin >> a[i];
	int ans = 0;
	F(i, 0, n){
		if(a[i] > l && (i == 0 || a[i - 1] <= l))++ans;
	}
	F(i, 0, m){
		int tp;
		cin >> tp;
		if(!tp){cout << ans << '\n'; cont;}
		int j, x;
		cin >> j >> x;
		--j;
		if(a[j] <= l && a[j] + x > l && (j > 0 && j < n - 1 && a[j - 1] > l && a[j + 1] > l))--ans;
		if(a[j] <= l&& a[j] + x > l&& (j == 0 || a[j - 1] <= l)&& (j + 1 == n || a[j + 1] <= l))++ans;
		a[j] += x;
	}
	return 0;
}