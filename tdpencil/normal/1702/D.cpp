#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int t=1;

const int mxN=2e5;
int a[mxN];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int c =0 ;
		for (char p : s)
			c+=(p-'a'+1);
		string t;
		int p;
		cin >> p;
		int n = s.size();
		vector<int> idx(n);
		iota(all(idx), 0);
		sort(idx.begin(), idx.end(), [&](const auto a, const auto b) {
			return s[a] > s[b];
		});
		set<int> fb;
		for (int i = 0; i < n; i++) {
			if(c>p) {
				c-=s[idx[i]]-'a'+1;
				fb.insert(idx[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			if(fb.count(i)) 
				continue;
			t+=s[i];
		}
		cout << t << "\n";

	}
}