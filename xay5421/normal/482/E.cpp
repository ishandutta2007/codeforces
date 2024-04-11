#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50005;
int n,fa[N],p[N],ch[N][2],val[N],sz[N],dsz[N],tag[N];ll w[N],sum[N],ans;vector<int>g[N];
void upd(int k1){
	sz[k1]=dsz[k1]+sz[ch[k1][0]]+sz[ch[k1][1]];
	sum[k1]=1ll*val[k1]*dsz[k1]+sum[ch[k1][0]]+sum[ch[k1][1]];
}
void pst(int k1,int k2){tag[k1]+=k2,w[k1]+=1ll*dsz[k1]*k2;}
void psd(int k1){if(tag[k1])pst(ch[k1][0],tag[k1]),pst(ch[k1][1],tag[k1]),tag[k1]=0;}
bool isr(int k1){return ch[fa[k1]][0]!=k1&&ch[fa[k1]][1]!=k1;}
int get(int k1){return ch[fa[k1]][1]==k1;}
void rtt(int k1){
	int k2=fa[k1],k3=get(k1);
	if(!isr(k2))ch[fa[k2]][get(k2)]=k1;fa[k1]=fa[k2];
	ch[k2][k3]=ch[k1][k3^1],fa[ch[k1][k3^1]]=k2;
	ch[k1][k3^1]=k2,fa[k2]=k1;
	upd(k2),upd(k1);
}
void splay(int k1){
	static int q[N];q[*q=1]=k1;
	for(int i=k1;!isr(i);q[++*q]=fa[i],i=fa[i]);
	for(int i=*q;i>=1;--i)psd(q[i]);
	for(;!isr(k1);rtt(k1))if(!isr(fa[k1]))rtt(get(k1)==get(fa[k1])?fa[k1]:k1);
}
void access(int k1){
	for(int i=0;k1;i=k1,k1=fa[k1]){
		splay(k1),dsz[k1]+=sz[ch[k1][1]];
		ch[k1][1]=i,dsz[k1]-=sz[ch[k1][1]];
		upd(k1);
	}
}
void dfs(int k1){
	w[k1]=dsz[k1]=1;
	for(int j:g[k1])dfs(j),w[k1]+=2ll*dsz[k1]*dsz[j],dsz[k1]+=dsz[j];
	ans+=w[k1]*val[k1];
	upd(k1);
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i)scanf("%d",&fa[i]),g[fa[i]].push_back(i),p[i]=fa[i];
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	dfs(1);
	printf("%.20lf\n",1.0*ans/n/n);
	int Q;scanf("%d",&Q);
	while(Q--){
		char c;while(!isupper(c=getchar()));
		int k1,k2;scanf("%d%d",&k1,&k2);
		if(c=='P'){
			access(k2),splay(k1);
			if(!fa[k1])swap(k1,k2);
			int k3=p[k1];
			access(k3),splay(k3);
			dsz[k3]-=sz[k1];
			pst(k3,-sz[k1]*2);
			upd(k3),ans-=sum[k3]*sz[k1]*2; 
			access(k2),splay(k2);
			ans+=sum[k2]*sz[k1]*2;
			pst(k2,sz[k1]*2);
			dsz[k2]+=sz[k1];
			upd(k2);
			fa[k1]=k2;
			p[k1]=k2;
		}else{
			splay(k1);
			ans+=(k2-val[k1])*w[k1];
			val[k1]=k2;
		}
		printf("%.20lf\n",1.0*ans/n/n);
	}
	return 0;
}