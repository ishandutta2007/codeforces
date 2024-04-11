// LUOGU_RID: 90774112
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int n,a[N],b[N];
void solve(){
	n=in();
	ll ans=0;
	for(int i=1;i<=n;i++)a[i]=in(),b[a[i]+1]=i;
	int L=n,R=1;ans=0;
	for(int i=1;i<=n;i++){
		L=min(L,b[i+1>>1]);
		R=max(R,b[i+1>>1]);
		int lp=max(1,R-i+1),rp=min(L,n-i+1);
		if(lp<=rp)ans+=rp-lp+1;
	}
	printf("%lld\n",ans);
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}