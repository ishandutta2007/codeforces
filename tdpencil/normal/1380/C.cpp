#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
const int mxN=2e5;
map<int, bool> used;
int a[mxN], n, x;
ll mn, cur;
int ans;
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
	int t; cin >> t;

	while(t--) {
		cin >> n >> x;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a,a+n);
		int r=n-1;
		ans=0;
		cur=1;
		while(~r) {
			mn = a[r--];
			if(mn*cur>=x) {
				++ans;	
				cur=1;
			} else {
				++cur;		
			}
		}
		cout << ans << '\n';
	}	
}