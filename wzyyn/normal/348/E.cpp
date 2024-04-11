#include<bits/stdc++.h>
using namespace std;
#define D isdigit(c=getchar())
inline int getint(){
	int c,l=0,x;
	for(;!D;l=c);for(x=c^'0';D;x=x*10+(c^'0'));
	return l=='-'?-x:x;
}
const int N=232131;
int tp[N],ans,sum,G[N],to[N],ne[N],da[N],xb;
int c[N],d[N],a[N],fa[N],dp[N],mdp[N];
int sl[N],d1[N],d2[N],mx,sz[N],n,m,rt;
void add(int x,int y,int z){
	ne[xb]=G[x];to[xb]=y;da[xb]=z;G[x]=xb++;
}
void dfs1(int x,int*d,int fa=0){
	if(c[x]&&d[x]>d[mx])mx=x;
	for(int i=G[x];~i;i=ne[i])
		if(to[i]!=fa){
			d[to[i]]=d[x]+da[i];
			dfs1(to[i],d,x);
		}
}
void dfs2(int x,int y=0){
	tp[x]=y;sz[x]=c[x];sl[x]=c[x];mdp[x]=c[x]?dp[x]:-2;
	for(int i=G[x];~i;i=ne[i])
		if(to[i]!=fa[x]){
			fa[to[i]]=x;
			dp[to[i]]=dp[x]+da[i];
			dfs2(to[i],fa[x]?y:to[i]);
			if(sz[to[i]]){
				sz[x]+=sz[to[i]];
				if(mdp[to[i]]>mdp[x]){
					mdp[x]=mdp[to[i]];sl[x]=sl[to[i]];
				}else if(mdp[to[i]]==mdp[x])sl[x]+=sl[to[i]];
			}
		}
}
 
int main(){
	n=getint();m=getint();memset(G,-1,sizeof(G));
	for(int i=1;i<=m;i++)c[a[i]=getint()]=1;
	for(int i=1;i<n;i++){
		int u=getint(),v=getint(),l=getint();
		add(u,v,l);add(v,u,l);
	}
	dfs1(a[1],d1);dfs1(mx,d2);d1[mx]=0;dfs1(mx,d1);
	int mn=-1,rt=1;
	for(int i=1;i<=n;i++)
		if(d1[i]+d2[i]==d1[mx]&&min(d1[i],d2[i])>mn){
			rt=i;mn=min(d1[i],d2[i]);
		}
	dfs2(rt);
	int mx1=-1,mid1=0,mx2=-1,mid2=0,mid=0;
	for(int i=G[rt];~i;i=ne[i]){
		if(mdp[to[i]]>mx1){
			mx2=mx1;mx1=mdp[to[i]];mid2=mid1;mid1=to[i];
		}else if(mdp[to[i]]>mx2)mx2=mdp[to[i]],mid2=to[i];
	}
	for(int i=G[rt];~i;i=ne[i])
		if(to[i]!=mid1&&mdp[to[i]]==mx2)mid++;
	for(int i=1;i<=n;i++)
		if(!c[i]){
			int as=0;
			if(i==rt)as=m;
			else{
				as+=sz[i];
				if(sl[i]==sl[tp[i]]&&mdp[i]==mdp[tp[i]]){
					if(mdp[i]==mx1&&mx2!=mx1)as+=m-sz[mid1];
					else if(mid==1&&tp[i]==mid1)as+=sz[mid2];
					else if(mdp[i]==mx2&&mid==1)as+=sz[mid1];
				}
			}
			if(as>ans){
				ans=as;sum=1;
			}else if(as==ans) sum++;
		}
	printf("%d %d\n",ans,sum);
	return 0;
}
//orz shenzhebei