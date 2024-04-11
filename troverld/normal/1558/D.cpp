#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int T,n,m,cnt,rt,fac[N+10],inv[N+10];
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct Treap{int ch[2],rd,sz,val,tag;}t[200100];
int newnode(int val){int x=++cnt;lson=rson=t[x].tag=0,t[x].val=val,t[x].rd=rand()*rand(),t[x].sz=1;return x;}
void ADD(int x,int y=1){t[x].val+=y,t[x].tag+=y;}
void pushup(int x){t[x].sz=t[lson].sz+t[rson].sz+1;}
void pushdown(int x){if(lson)ADD(lson,t[x].tag);if(rson)ADD(rson,t[x].tag);t[x].tag=0;}
void splitbyval(int x,int k,int &u,int &v){
	if(!x){u=v=0;return;}
	pushdown(x);
	if(t[x].val>=k)v=x,splitbyval(lson,k,u,lson);
	else u=x,splitbyval(rson,k,rson,v);
	pushup(x);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd<t[y].rd){pushdown(x),t[x].ch[1]=merge(t[x].ch[1],y),pushup(x);return x;}
	else{pushdown(y),t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y);return y;}
}
void Insert(int val){
	int u,v,w;
	splitbyval(rt,val,u,v);
	if(v)ADD(v);
	splitbyval(v,val+2,v,w);
	rt=merge(merge(u,v?v:newnode(val+1)),w);
}
int main(){
	fac[0]=1;for(int i=1;i<=N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[N]=ksm(fac[N]);for(int i=N;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),cnt=rt=0;
		for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),Insert(y);
		int a=t[rt].sz+1,b=n-a;
//		printf("AA:%d %d\n",a,b);
		printf("%d\n",1ll*fac[n+b]*inv[n]%mod*inv[b]%mod);
	}
	return 0;
}