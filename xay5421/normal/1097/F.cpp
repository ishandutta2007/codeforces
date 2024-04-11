// author: xay5421
// created: Wed Dec  9 21:50:07 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
typedef bitset<7005> BIT;
int n,Q,p[7005],mu[7005];
bool ban[7005];
BIT f[N],g[7005],h[7005];
void sieve(){
	ban[0]=ban[1]=1,mu[1]=1;
	rep(i,2,7004){
		if(!ban[i]){
			p[++*p]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=*p&&i*p[j]<7005;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
			mu[i*p[j]]=-mu[i];
		}
	}
	for(int i=1;i<7005;++i){
		for(int j=i;j<7005;j+=i){
			g[j].set(i);
			if(mu[j/i]){
				h[i].set(j);
			}
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	sieve();
	scanf("%d%d",&n,&Q);
	while(Q--){
		int o,x,y,z;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1){
			f[x]=g[y];
		}else if(o==2){
			scanf("%d",&z);
			f[x]=f[y]^f[z];
		}else if(o==3){
			scanf("%d",&z);
			f[x]=f[y]&f[z];
		}else{
			BIT tem=f[x]&h[y];
			putchar((tem.count()&1)+48);
		}
	}
	puts("");
	return 0;
}