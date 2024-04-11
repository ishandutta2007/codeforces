#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,k;
	while(cin>>n>>m>>k){
	if(k<n){
		cout<<k+1<<" "<<1<<endl;
	} else {
		k -= n;
		--m;
		ll num = k/m;
		ll r = k%m;
		if(num%2==0)cout<<n - num <<" "<<2+r<<endl;
		else cout<<n - num <<" "<<m+1-r<<endl;
	}
	}
}