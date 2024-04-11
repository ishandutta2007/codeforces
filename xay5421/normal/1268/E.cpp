#include<bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=500005;
int n,m,f[N];
int pp=1,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int st[N],top,dfn[N],low[N],ind,pre[N],goes[N],offset[N];
map<pair<int,int>,int>Eid;
void tarjan(int k1,int k2){
	st[++top]=k1,dfn[k1]=low[k1]=++ind;
	for(int i=lnk[k1];i;i=nxt[i])if(i/2!=k2/2){
		if(!dfn[to[i]]){
			pre[to[i]]=i;
			tarjan(to[i],i),low[k1]=min(low[k1],low[to[i]]);
			if(low[to[i]]>=dfn[k1]){
				vector<int>cyc;
				cyc.PB(Eid[{st[top],k1}]);
				do{
					cyc.PB(pre[st[top]]);
				}while(st[top--]!=to[i]);
				rotate(cyc.begin(),min_element(cyc.begin(),cyc.end()),cyc.end());
				int pos=max_element(cyc.begin(),cyc.end())-cyc.begin();
				bool ok=1;
				rep(i,0,pos-1){
					if(cyc[i]>cyc[i+1])ok=0;
				}
				rep(i,pos,SZ(cyc)-2)
					if(cyc[i]<cyc[i+1])ok=0;
				if(ok){
					goes[cyc[pos]/2]=cyc[0]/2;
				}
			}
		}
		else{
			low[k1]=min(low[k1],dfn[to[i]]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
		Eid[{k1,k2}]=i*2;
		Eid[{k2,k1}]=i*2+1;
	}
	tarjan(1,0);
	rep(i,1,n)f[i]=1;
	per(i,m,1){
		int k1=to[i*2+1],k2=to[i*2];
		int w=f[k1]+f[k2]-offset[i];
		f[k1]=f[k2]=w;
		if(goes[i]){
			offset[goes[i]]=w;
		}
	}
	rep(i,1,n)printf("%d ",f[i]-1);
	puts("");
	return 0;
}