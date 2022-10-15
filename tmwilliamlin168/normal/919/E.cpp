#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxP=1e6+3;
ll cnt[mxP];

ll inv(ll a, ll m) {
	return (a%=m)<=1?1:((1-inv(m%a, a)*m)/a+m)%m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, p, x, pow1, pow2, ans=0;
	cin >> a >> b >> p >> x;
	if(a==1)
		cout << (x-b+p)/p;
	else {
		pow1=b;
		for(int i=0; i<p-1; ++i) {
			++cnt[pow1];
			pow1=pow1*inv(a, p)%p;
		}
		pow2=a;
		for(int i=1; i<p; ++i) {
			ans+=cnt[i*pow2%p];
			pow2=pow2*a%p;
		}
		ans*=x/(p*(p-1));
		memset(cnt, 0, 8*p);
		pow1=b;
		for(int i=0; (i+1)*p<=x%(p*(p-1)); ++i) {
			++cnt[pow1];
			pow1=pow1*inv(a, p)%p;
		}
		pow2=a;
		for(int i=1; i<p; ++i) {
			ans+=cnt[i*pow2%p];
			if(i<=x%p&&i*pow2%p==pow1)
				++ans;
			pow2=pow2*a%p;
		}
		cout << ans;
	}
}