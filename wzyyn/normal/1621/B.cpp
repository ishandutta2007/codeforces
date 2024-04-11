#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,l,r;
	long long c;
	scanf("%d",&n);
	scanf("%d%d%lld",&l,&r,&c);
	int pl=l,pr=r;
	long long vl=c,vr=c,vm=c;
	printf("%lld\n",c);
	for (int i=2;i<=n;i++){
		scanf("%d%d%lld",&l,&r,&c);
		if (l<pl) pl=l,vl=vm=1ll<<60;
		if (r>pr) pr=r,vr=vm=1ll<<60;
		if (l==pl) vl=min(vl,c);
		if (r==pr) vr=min(vr,c);
		if (l==pl&&r==pr) vm=min(vm,c);
		printf("%lld\n",min(vm,vl+vr));
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}