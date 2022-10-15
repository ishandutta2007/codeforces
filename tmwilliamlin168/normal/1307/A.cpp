#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
 int t;
 cin >> t;
 while(t--) {
	int n, d;
	cin >> n >> d;
	int a[n];
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<n; ++i) {
		while(a[i]) {
			if(i>d)
				break;
			d-=i;
			++a[0];
			--a[i];
		}
	}
	cout << a[0] << endl;
 }
}