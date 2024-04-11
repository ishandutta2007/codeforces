#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7, I2=5e8+4;
int n;
ll T, t[mxN], pI2[mxN+1], iv[mxN+1], f1[mxN+1], f2[mxN+1], ans;

ll nck(int n, int k) {
	return f1[n]*f2[k]%M*f2[n-k]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> T;
	for(int i=0; i<n; ++i) {
		cin >> t[i];
		if(i)
			t[i]+=t[i-1];
	}
	pI2[0]=1;
	for(int i=0; i<n; ++i)
		pI2[i+1]=pI2[i]*I2%M;
	iv[1]=1;
	for(int i=2; i<=n; ++i)
		iv[i]=M-M/i*iv[M%i]%M;
	f1[0]=f2[0]=1;
	for(int i=1; i<=n; ++i) {
		f1[i]=f1[i-1]*i%M;
		f2[i]=f2[i-1]*iv[i]%M;
	}
	ll rt=1;
	int nr=0;
	for(int i=0; i<n; ++i) {
		//cout << "i " << i << endl;
		rt=(rt-nck(i, nr)*pI2[i+1]%M+M)%M;
		ll l=t[i], r=t[i]+i+1;
		if(r>T&&l<=T) {
			int tr=r-T-1;
			//cout << tr << endl;
			while(nr<tr) {
				++nr;
				rt=(rt+nck(i+1, nr)*pI2[i+1])%M;
			}
			ans=(ans+1-rt+M)%M;
		} else if(l<=T)
			ans=(ans+1)%M;
	}
	cout << ans;
}