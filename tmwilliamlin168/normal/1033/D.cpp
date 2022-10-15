#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=500, M=998244353;
int n;
ll a[mxN], ans=1, irb[5]={0, 0, (ll)1.5e9, (ll)1.3e6, 37606};
unordered_map<ll, int> mp1, mp2;
vector<ll> tp;

ll f(ll x, int p) {
	ll lb=1, rb=irb[p];
	while(lb<=rb) {
		ll mb=(lb+rb)/2, a=1;
		for(int i=0; i<p; ++i)
			a*=mb;
		if(a==x)
			return mb;
		if(a<x)
			lb=mb+1;
		else
			rb=mb-1;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	mp1.reserve(2*n);
	mp2.reserve(n);
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		int j=4;
		for(; j>=2; --j) {
			ll p=f(a[i], j);
			if(p!=-1) {
				mp1[p]+=j;
//				cout << i << " " << j << endl;
				a[i]=1;
				tp.push_back(p);
				break;
			}
		}
		if(j<2) {
			for(j=0; j<i; ++j) {
				ll g=__gcd(a[i], a[j]);
				if(g>1&&g<a[i])
					tp.push_back(g);
			}
		}
	}
//	cout << "hi2" << endl;
	for(ll p : tp) {
//		cout << p << endl;
		for(int i=0; i<n; ++i) {
			if(a[i]%p==0) {
				++mp1[p];
				++mp1[a[i]/p];
				a[i]=1;
			}
		}
	}
	for(int i=0; i<n; ++i)
		if(a[i]>1)
			++mp2[a[i]];
	for(auto it=mp1.begin(); it!=mp1.end(); ++it)
		ans=ans*(it->second+1)%M;
//	cout << ans << endl;
	for(auto it=mp2.begin(); it!=mp2.end(); ++it)
		ans=(ans*(it->second+1))*(it->second+1)%M;
	cout << ans;
}