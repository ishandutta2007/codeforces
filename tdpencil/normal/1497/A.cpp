#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
const int mxN = 2e5+5;
const int mnN = 1e5+5;
const int grn = 105;
const int grN = 505;
const int griN = 1005;
const int mxGriN= 5005;
const int mxDP = 7005;

int ar[mxN];
ll dp3[grn][grn][grn];
ll dp2[griN][griN];
ll dp1[mnN];
int n, m;
int a[mxN];
int cnt[grn];
void solve() {
	cin >> n;
	vector<int> b(n);
	for(int i =0; i < n; i++)
		cin >> b[i];

	sort(b.begin(), b.end());
	for(int i =0; i < n; i++) 
		cnt[b[i]]++;

	vector<int> ans;
	for(int i=0; i <= 100; i++) 
		if(cnt[i]) {
			ans.push_back(i);
			cnt[i]--;
		}

	for(int i=0;i <=100; i++) {
		for(int j=0;j<cnt[i];j++)
			ans.push_back(i);
	}

	for(auto &e: ans)
		cout << e << " ";
	cout << "\n";
	memset(cnt, 0, sizeof(cnt));
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}