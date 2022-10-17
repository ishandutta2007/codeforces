#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
typedef long long ll;
const int N=1e6+5;
int n,m;
int a[N];
ll ans;
void upd(int p,int v){
	if(p<1)return;
	ll val=0;
	if(a[p]==a[p+1])val=(ll)p*(n-p);
	if(v==1)ans-=val;
	else ans+=val;
}
int main(){
	n=in(),m=in();
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=1;i<=n;i++)ans+=(ll)i*(n-i+1);
	for(int i=1;i<n;i++)upd(i,1);
	while(m--){
		int p=in(),v=in();
		upd(p-1,-1),upd(p,-1);
		a[p]=v;
		upd(p-1,1),upd(p,1);
		printf("%lld\n",ans);
	}
	return 0;
}