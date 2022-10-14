#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
// ll m, k, x, y;

string s;
int n, m, q;
const int mxN = 2e5+1;
int a[mxN+1];

void solve() {
	cin >> n >> m;
	vector<int> cnt(m);
	for(int i=0;i<n;i++)
		cin >> a[i], ++cnt[a[i]%m];
	
	
	int ans=0;
	for(int i=0;i<=m/2;i++) {
		int f=i,s=(m-i)%m;
		// cout << "ARRAY\n";
		// cout << f << " : " << s << "\n";
		// cout << cnt[f] << " : " << cnt[s] << "\n";
		if(f==s) {
			if(cnt[f])
				ans++;
		} else {
			// not the same
			
			if(cnt[f] < cnt[s]) swap(f, s);
			// if(cnt[s]) cnt[f]--;
			if(cnt[s] == cnt[f]) {
				if(cnt[s]) cnt[f]-=cnt[s],ans++;
			} else {
				if(cnt[s]) cnt[f]-=cnt[s]+1,ans++;
			}
				
			ans += cnt[f];
		}
	}
	
	cout << ans << "\n";
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		// cout << "Case #" << case_num << ": ";
		solve();
	}
}