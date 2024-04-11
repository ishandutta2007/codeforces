#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int a[100000];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
 int t;
 cin >> t;
 while(t--) {
	int n, x;
	cin >> n >> x;
	int b=0;
	bool br=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(!br&&a[i]==x) {
			cout << 1;
			br=1;
		}
		b=max(b, a[i]);
	}
	if(!br) {
	if(x<b)
		cout << 2;
	else if(x%b==0)
		cout << x/b;
	else
		cout << x/b+1;
	}
	cout << "\n";
 }
}