#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[200100],dsu[200100],mny[200100],mnx[200100];
ll mnv[200100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
ll calc(int x){
	for(int i=1;i<=n;i++)dsu[i]=i;
	ll ret=0;
	for(int _=n;_>1;){
		int l=1;while(find(l)==find(1))l++;
		int r=n;while(find(r)==find(n))r--;
		for(int i=1;i<=n;i++)if(x+a[i]>=0){
			if(find(i)==find(1))mny[i]=l,mnv[i]=1ll*a[i]*a[l]+1ll*x*(a[i]+a[l]);
			else mny[i]=1,mnv[i]=1ll*a[i]*a[1]+1ll*x*(a[i]+a[1]);
		}else{
			if(find(i)==find(n))mny[i]=r,mnv[i]=1ll*a[i]*a[r]+1ll*x*(a[i]+a[r]);
			else mny[i]=n,mnv[i]=1ll*a[i]*a[n]+1ll*x*(a[i]+a[n]);
		}
		for(int i=1;i<=n;i++)mnx[i]=i;
		for(int i=1;i<=n;i++)if(mnv[mnx[find(i)]]>mnv[i])mnx[find(i)]=i;
		for(int i=1;i<=n;i++)if(dsu[i]==i&&find(mny[mnx[i]])!=i){
			_--;
			ret+=mnv[mnx[i]];
			dsu[i]=find(mny[mnx[i]]);
		}
	}
	return ret;
}
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1); 
	int l=-2001000,r=2001000;
	while(r-l>5){
		int lmid=(l+l+r)/3,rmid=(l+r+r)/3;
		if(calc(lmid)>calc(rmid))r=rmid;else l=lmid;
	}
	if((r<-2000010||l>2000010)&&calc(l)!=calc(r)){puts("INF");return;}
	ll res=0x8080808080808080;
	for(int i=l;i<=r;i++)res=max(res,calc(i));
	printf("%lld\n",res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}