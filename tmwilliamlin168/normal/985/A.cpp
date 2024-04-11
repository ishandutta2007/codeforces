#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int *p = new int[n/2];
	for(int i=0; i<n/2; ++i)
		cin >> p[i];
	sort(p, p+n/2);
	int a1=0, a2=0;
	for(int i=0; i<n/2; ++i) {
		a1+=abs(p[i]-2*i-1);
		a2+=abs(p[i]-2*i-2);
	}
	cout << min(a1, a2);
}