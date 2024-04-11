#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5, M=998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
	string a;
	cin >> n >> m;
	long long p1[mxN], ans=0;
	p1[n-1]=1;
	for(int i=n-2; i>=0; --i)
		p1[i]=p1[i+1]*2%M;
	cin >> a;
	for(int i=0; i<n; ++i)
		if(a[i]=='0')
			p1[i]=0;
	for(int i=n-2; i>=0; --i)
		p1[i]=(p1[i]+p1[i+1])%M;//, cout << p1[i] << endl;
	cin >> a;
	for(int i=0; i<m; ++i)
		if(a[i]=='1')
			ans=(ans+p1[max(i+n-m, 0)])%M;//, cout << i+n-m << endl;
	cout << ans;
}