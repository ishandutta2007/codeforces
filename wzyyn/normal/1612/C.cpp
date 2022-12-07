#include<bits/stdc++.h>

using namespace std;

void solve(){
	int k;
	long long x;
	scanf("%d%lld",&k,&x);
	int l=1,r=2*k-1;
	long long re=r;
	while (l<=r){
		int mid=(1ll*l+r)/2;
		long long val;
		if (mid<=k) val=1ll*mid*(mid+1)/2;
		else val=1ll*k*k-1ll*(2*k-mid)*(2*k-mid-1)/2;
		if (val>=x) re=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}