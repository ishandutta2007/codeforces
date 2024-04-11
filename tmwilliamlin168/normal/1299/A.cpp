#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=29; ~i; --i) {
		int c=0, b;
		for(int j=0; j<n; ++j)
			if(a[j]>>i&1) {
				++c;
				b=j;
			}
		if(c==1) {
			swap(a[b], a[0]);
			break;
		}
	}
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
}