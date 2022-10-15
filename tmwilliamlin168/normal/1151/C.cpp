#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;

ll f(ll a) {
	ll s=0;
	ll lb=0, rb=1e18;
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		ll c[2]={}, p=1;
		for(int i=0; c[0]<mb; i^=1, p*=2) {
			if(i) {
				c[1]+=p;
			} else {
				if(c[0]+p>=mb) {
					c[0]=mb;
				} else {
					c[0]+=p;
				}
			}
		}
		if(c[0]+c[1]<=a)
			lb=mb;
		else
			rb=mb-1;
	}
	s+=(lb%M)*(lb%M)%M;
	//cout << lb << endl;
	lb=0, rb=1e18;
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		ll c[2]={}, p=1;
		for(int i=0; c[1]<mb; i^=1, p*=2) {
			if(i) {
				if(c[1]+p>=mb) {
					c[1]=mb;
				} else {
					c[1]+=p;
				}
			} else {
				c[0]+=p;
			}
		}
		if(c[0]+c[1]<=a)
			lb=mb;
		else
			rb=mb-1;
	}
	s+=2*(lb%M)*(lb%M+1)%M*(M+1)/2%M;
	//cout << lb << endl;
	return s%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll l, r;
	cin >> l >> r;
	cout << (f(r)-f(l-1)+M)%M;
}