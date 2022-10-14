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
int n, m;
int cnt[mxGriN];
int best[mxGriN];
int a[mxGriN];
void solve() {
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=0;i<n; i++) {
		for(int j=1;j<=n;j++)
			cnt[j]=0;
		int bst=5004;
		for(int j=i;j<n;j++) {
			cnt[a[j]]++;
			if(cnt[a[j]] > cnt[bst] || (cnt[a[j]] == cnt[bst] && a[j] < bst)) {
				bst=a[j];
			}
			best[bst]++;
		}
	}
	for(int i=0;i<n;i++)
		cout << best[i+1] << " \n"[i==n-1];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)
		solve();
}