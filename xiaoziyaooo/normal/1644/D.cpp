#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,mod=998244353;
int n,m,T,k,p,stp;
int x[maxn],y[maxn],visx[maxn],visy[maxn];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		stp++;
		scanf("%d%d%d%d",&n,&m,&k,&p);
		for(int i=1;i<=p;i++)
			scanf("%d%d",&x[i],&y[i]);
		int tot=p,xt=0,yt=0;
		for(int i=p;i>=1;i--){
			if(xt==n||yt==m||(visx[x[i]]==stp&&visy[y[i]]==stp))
				tot--;
			if(visx[x[i]]!=stp)
				visx[x[i]]=stp,xt++;
			if(visy[y[i]]!=stp)
				visy[y[i]]=stp,yt++;
		}
		printf("%d\n",ksm(k,tot));
	}
	return 0;
}