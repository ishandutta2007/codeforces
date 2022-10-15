#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a[1000];

void solve() {
	int n;
	cin >> n;
	if(n<4) {
		cout << "-1\n";
		return;
	}
	for(int i=0; i<n/5; ++i) {
		int j=i*5;
		a[j]=j+3;
		a[j+1]=j+1;
		a[j+2]=j+5;
		a[j+3]=j+2;
		a[j+4]=j+4;
	}
	if(n%5==1) {
		a[n-1]=n;
	} else if(n%5==2) {
		a[n-3]=n-1;
		a[n-2]=n-3;
		a[n-1]=n;
	} else if(n%5==3) {
		a[n-4]=n-2;
		a[n-3]=n;
		a[n-2]=n-4;
		a[n-1]=n-1;
	} else if(n%5==4) {
		a[n-4]=n-1;
		a[n-3]=n-3;
		a[n-2]=n;
		a[n-1]=n-2;
	}
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}