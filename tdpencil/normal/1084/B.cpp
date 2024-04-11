#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
const int mxN=2e5;
int n, a[1005];
ll s;
ll c;
int main() {
	int t=1;
	while(t--) {
		cin >> n >> s;
		for(int i = 0; i < n; i++)
			cin >> a[i], c+=a[i];
		if(c<s) {
			cout << -1 << '\n';
			break;
		} else if(c==s) {
			cout << 0 << '\n';
			return 0;
		}	
		sort(a, a+n);	
		c=0;
		bool w=1;
		for(int i=n-1;~(i-1);i--) {
			if(a[i]-a[0]<=s) {
				s-=a[i]-a[0];
			} else {
				cout << *min_element(a,a+n) << '\n';
				return 0;
			}
			
			a[i]=a[0];
		}
		if(!s) cout << *min_element(a,a+n);
		else cout << *min_element(a,a+n) - ((s+n-1)/n);
	}
}