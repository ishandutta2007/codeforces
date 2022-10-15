#include <bits/stdc++.h>
using namespace std;

long long n, k, s, a[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> s;
	if(s<k) {
		cout << "NO";
		return 0;
	}
	s-=(n-1)*k;
	if(s>0) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i=0; i<k; ++i)
		a[i]=n-1;
	for(int i=k-1; i>=0&&s<0; --i) {
		int b=min(-s, n-2);
		a[i]-=b;
		s+=b;
	}
	for(int i=0, b=1, c=1; i<k; ++i, c=-c) {
		b+=c*a[i];
		cout << b << " ";
	}
}