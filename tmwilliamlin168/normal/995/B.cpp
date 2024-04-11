#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, a[200], a2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<2*n; ++i)
		cin >> a[i];
	for(int i=0; i<2*n; i+=2) {
		int j=2*n;
		while(a[--j]!=a[i]);
		while(j-1>i) {
			swap(a[j-1], a[j]);
			++a2;
			--j;
		}
	}
	cout << a2;
}