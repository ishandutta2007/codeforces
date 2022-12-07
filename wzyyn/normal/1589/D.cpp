#include<bits/stdc++.h>

using namespace std;

long long query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	long long x;
	scanf("%lld",&x);
	return x;
}
int F(long long s){
	int l=1,r=1e9,p=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (1ll*mid*(mid-1)/2<=s)
			p=mid,l=mid+1;
		else r=mid-1;
	}
	return p;
}
void solve(){
	int n;
	scanf("%d",&n);
	long long S=query(1,n);
	int l=1,r=n-1,p=n;
	while (l<=r){
		int mid=(l+r)/2;
		if (query(1,mid)==S)
			p=mid,r=mid-1;
		else l=mid+1;
	}
	int dr=S-query(1,p-1);
	int ansr=p,ansm=ansr-dr,ansl=ansm-F(S-1ll*dr*(dr+1)/2);
	printf("! %d %d %d\n",ansl,ansm,ansr);
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}