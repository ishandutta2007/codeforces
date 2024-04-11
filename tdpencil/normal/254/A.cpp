#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define pb push_back
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

void solve() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n; 
	cin >> n;
	
	vector<int> a(2*n);
	vector<vi> cnt(5001);
	for(int i =0;i<2*n;i++) {
		cin >> a[i];
		cnt[a[i]].push_back(i);
	}
	vector<int> l, r;
	for(int i=1;i<=5000;i++) {
		if(sz(cnt[i])%2) {
			cout << -1 << "\n";
			return;
		}
		for(int j=0;j<sz(cnt[i]);j+=2) {
			l.pb(cnt[i][j]);
			r.pb(cnt[i][j+1]);
		}
	}

	//cout << sz(l) << "\n";
	for(int i=0;i<n;i++) {
		cout << l[i]+1 << " " << r[i]+1 << nl;
	}
	
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int t = 1;
	//cin >> t;
    while(t--) {
        solve();
    }
}