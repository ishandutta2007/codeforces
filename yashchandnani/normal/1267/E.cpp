#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m; cin >> n >> m;
	int a[m][n];
	rep(i,m) rep(j,n) cin >> a[i][j];
	int ans = m;
	vi anss; rep(i,m) anss.pb(i);
	rep(j,n-1){
		vector <pii> lol;
		rep(i,m){
			lol.pb(mp(a[i][j] - a[i][n-1], i));
		}
		sort(all(lol));
		reverse(all(lol));
		int cur = 0; int tans = 0;
		rep(i,m){
			if(lol[i].fst + cur >= 0) cur += lol[i].fst;
			else break;
			tans++;
		}
		if(m - tans < ans){
			ans = m - tans;
			anss.clear();
			while(tans < m){
				anss.pb(lol[tans].snd);
				tans++;
			}
		}
	}
	cout << ans << endl;
	rep(i,sz(anss)){
		cout << anss[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}