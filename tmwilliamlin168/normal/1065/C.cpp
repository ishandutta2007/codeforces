#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, hi, c[200001]={}, mn=1e9, ans=0;
	cin >> n >> k;
	for(int i=0; i<n; ++i) {
		cin >> hi;
		++c[hi];
		mn=min(hi, mn);
	}
	for(int i=200000; i; --i)
		c[i-1]+=c[i];
	for(int i=200000, cs=0; i>mn; --i) {
		if(cs+c[i]>k) {
			++ans;
			cs=0;
		}
		cs+=c[i];
		if(cs>0&&i==mn+1)
			++ans;
	}
	cout << ans;
}