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

int a[mxN], c[mxN];
void solve() {
	cin >> n;
	int mx=n-1;
	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=n-1; ~i; --i) {
		if(mx>i) mx=i;
		int toGet = max(0, a[i] - (i - mx));
		while(toGet>0) {
			c[mx]=1;
			mx--;
			if(mx<0) {
				mx=0;
				break;
			};
			--toGet;
		}
	}
	for(int i=0;i<n;i++)
		cout << c[i] << " ";
	memset(c, 0, 4*n);
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	while(t--)
		solve();
}