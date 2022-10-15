#include <bits/stdc++.h>
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
				31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
				31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
				31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
				31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i+n<=60; ++i) {
		bool ok=true;
		for(int j=0; j<n; ++j) {
			if(months[i+j]!=a[j]) {
				ok=false;
				break;
			}
		}
		if(ok) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}