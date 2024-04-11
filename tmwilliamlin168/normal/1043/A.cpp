#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define array a

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a[100], k=0, s1=0, s2=0;
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i], k=max(a[i], k), s1+=a[i];
	s2=k*n-s1;
	while(s2<=s1) {
		++k;
		s2+=n;
	}
	cout << k;
}