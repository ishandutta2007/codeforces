#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1000005;
int n,m,nid,we[50005];
vector<vector<int> >G[50005];
int pp,_pp,_lnk[N],lnk[N],nxt[N*2],to[N*2];
int ind,cnt,dfn[N],low[N],ins[N],top,st[N],bel[N];
void ae(int k1,int k2){
	//printf("ae %d %d\n",k1,k2);
	to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;
}
void tarjan(int k1){
	dfn[k1]=low[k1]=++ind,st[++top]=k1,ins[k1]=1;
	for(int i=lnk[k1];i;i=nxt[i]){
		if(!dfn[to[i]])tarjan(to[i]),low[k1]=min(low[k1],low[to[i]]);
		else if(ins[to[i]])low[k1]=min(low[k1],dfn[to[i]]);
	}
	if(low[k1]==dfn[k1]){
		++cnt;
		do{
			bel[st[top]]=cnt;
			ins[st[top]]=0;
		}while(st[top--]!=k1);
	}
}
bool chk(int mid){
	ind=cnt=0;
	pp=_pp;
	rep(i,1,nid)lnk[i]=_lnk[i];
	rep(i,1,m){
		if(we[i]>mid){
			ae(i,i+m);
		}
	}
	rep(i,1,nid)dfn[i]=low[i]=0;
	rep(i,1,nid)if(!dfn[i])tarjan(i);
	rep(i,1,m){
		if(bel[i]==bel[i+m])return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	nid=m+m;
	rep(i,1,m){
		int k1,k2,k3,k4;
		scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
		we[i]=k4;
		G[k1].PB({k2,k3,k4,i});
		G[k2].PB({k1,k3,k4,i});
	}
	rep(k1,1,n){
		sort(G[k1].begin(),G[k1].end(),[&](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});
		int sz=SZ(G[k1]);
		vector<int>A(sz);
		for(auto&x:A)x=++nid;
		vector<int>B(sz);
		for(auto&x:B)x=++nid;
		for(int i=0;i<sz;++i){
			if(i+1<sz)ae(A[i],A[i+1]),ae(B[i+1],B[i]);
			ae(G[k1][i][3],A[i]);
			ae(B[i],G[k1][i][3]+m);
			if(i){
				ae(G[k1][i][3],B[i-1]);
				ae(A[i-1],G[k1][i][3]+m);
			}
		}
		for(int l=0,r;l<sz;l=r){
			r=l+1;
			while(r<sz&&G[k1][l][1]==G[k1][r][1])++r;
			for(int i=l;i<r;++i)A[i]=++nid;
			for(int i=l;i<r;++i)B[i]=++nid;
			for(int i=l;i<r;++i){
				if(i+1<r)ae(A[i+1],A[i]),ae(B[i],B[i+1]);
				ae(A[i],G[k1][i][3]);
				ae(G[k1][i][3]+m,B[i]);
				if(i>l){
					ae(B[i-1],G[k1][i][3]);
					ae(G[k1][i][3]+m,A[i-1]);
				}
			}
		}
	}
	//puts("-----end-----");
	int l=0,r=1000000000,ans=r;
	_pp=pp;
	rep(i,1,nid)_lnk[i]=lnk[i];
	if(!chk(r)){
		puts("No");
		return 0;
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	chk(ans);
	puts("Yes");
	vector<int>res;
	rep(i,1,m)if(bel[i]<bel[i+m])res.PB(i);
	printf("%d %d\n",ans,SZ(res));
	for(auto x:res)printf("%d ",x);
	return 0;
}