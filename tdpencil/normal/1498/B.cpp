#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
#define pb push_back
// ll m, k, x, y;

// string s;
ll n, m,k;
const int mxN = 3e5+1;
const int M = 1e9+7;
void solve() {
	cin >> n >> k;
	vector<int> a(n);
	for(int &i : a)
		cin >> i;

	priority_queue<int> pq;
	for(int &i : a)
		pq.push(i);

	sort(a.rbegin(), a.rend());
	map<int, int> cnt;
	for(int &i : a)
		cnt[i]++;

	int ans=1,cur=0;
	while(pq.size()) {
		int x=pq.top();
		pq.pop();
		if(!cnt[x]) continue;
		if(cur + x > k) {
			int res = k - cur;
			int ch=-1;
			for(int j=1; j <= res; j*=2) {
				if(cnt[j])
					ch=j;
			}
			if(ch==-1) {
				ans++;
				pq.push(x);
				cur=0;
			} else {
				cnt[ch]--;
				cur += ch;
				// use again later
				pq.push(x);
			}
		} else {
			cur += x;
			cnt[x]--;
		}
	}

	cout << ans << "\n";

	
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}