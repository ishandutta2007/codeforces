#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



template <class T>
bool umin(T &x, T y) {
	if (x > y)
	{
		x = y;
		return 1;
	}
	return 0;
}
template <class T>
bool umax(T &x, T y) {
	if (x < y)
	{
		x = y;
		return 1;
	}
	return 0;
}
bool cmp(int a, int b) {
	return abs(a) > abs(b);
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	vector<vector<int>> neighbors(n, vector<int>(m));
	bool doesntfit=0;
	rep(i,0,n) {
		rep(j,0,m) {
			cin >> g[i][j];
			if(i) --g[i][j];
			if(i<n-1) --g[i][j];
			if(j) --g[i][j];
			if(j<m-1) --g[i][j];
			if(g[i][j]>0) {
				doesntfit=1;
			}
		}
	}

	if(doesntfit) {
		cout << "NO\n";
		return;
	}
	// otherwise just p


	// otherwise you can always make this work i think

	cout << "YES\n";
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			int x=0;
			if(i)++x;
			if(i<n-1)++x;
			if(j)++x;
			if(j<m-1) ++x;
			cout << x << " ";
		}
		cout << nl;
	}
	return;


}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
	cin >> t;
    while(t--) {
        solve();
    }
}