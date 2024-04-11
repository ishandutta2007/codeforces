#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 222222;
vector<int> v[N];
int x[2*N],y[2*N],z[2*N];
int fa[N],b[N],c[N];
LL d[N];
int p[2*N],sp,tin[N],tout[N];
LL T1[20*N],lazy[20*N];
void dfs(int u){
	int i,s;
	s=v[u].size();
	d[u]=d[fa[u]]+b[u];
	sp++;
	p[sp]=u;
	tin[u]=sp;
	for(i=0;i<s;i=i+1)
		dfs(v[u][i]);
	//sp++;
	//p[sp]=u;
	tout[u]=sp;
}
void build1(int k,int l,int r){
	if(l==r){
		T1[k]=d[p[l]]+c[p[l]];
		return;
	}
	int md;
	md=(l+r)/2;
	build1(k*2,l,md);
	build1(k*2+1,md+1,r);
	T1[k]=min(T1[k*2],T1[k*2+1]);
}
void modify1(int L,int R,LL V,int k,int l,int r){
	if(L>R||L>r||l>R)
		return;
	if(L==l&&R==r){
		T1[k]+=V;
		lazy[k]+=V;
		return;
	}
	int md;
	md=(l+r)/2;
	if(lazy[k]){
		T1[k*2]+=lazy[k];
		T1[k*2+1]+=lazy[k];
		lazy[k*2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	modify1(L,min(R,md),V,k*2,l,md);
	modify1(max(L,md+1),R,V,k*2+1,md+1,r);
	T1[k]=min(T1[k*2],T1[k*2+1]);
}
LL query1(int L,int R,int k,int l,int r){
	if(L>R||L>r||l>R)
		return (LL)1<<59;
	if(L==l&&R==r)
		return T1[k];
	int md;
	LL t;
	md=(l+r)/2;
	if(lazy[k]){
		T1[k*2]+=lazy[k];
		T1[k*2+1]+=lazy[k];
		lazy[k*2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	t=min(query1(L,min(R,md),k*2,l,md),query1(max(L,md+1),R,k*2+1,md+1,r));
	T1[k]=min(T1[k*2],T1[k*2+1]);
	return t;
}
int main()
{
	int n,q,i,t,tt,h;
	LL lt,lh,l;
	LL ans,s;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i=i+1){
		scanf("%d%d%d",x+i,y+i,z+i);
		v[x[i]].push_back(y[i]);
		fa[y[i]]=x[i];
		b[y[i]]=z[i];
	}
	for(i=n;i<n+n-1;i=i+1){
		scanf("%d%d%d",x+i,y+i,z+i);
		c[x[i]]=z[i];
	}
	d[1]=0;
	dfs(1);
	sp+=10;
	memset(lazy,0,sizeof(lazy));
	for(i=1;i<=n;i=i+1)
		modify1(tin[i],tin[i],d[i]+c[i],1,1,sp);
	//build1(1,1,sp);
	//for(i=1;i<=4*n;i=i+1)
	//	cout<<i<<' '<<T1[i]<<endl;
	while(q--){
		scanf("%d%d%d",&tt,&t,&h);
		if(tt==1){
			if(t<n){
				modify1(tin[y[t]],tout[y[t]],(LL)h-b[y[t]],1,1,sp);
				b[y[t]]=h;
			}
			else{
				modify1(tin[x[t]],tin[x[t]],(LL)h-c[x[t]],1,1,sp);
				c[x[t]]=h;
			}
		}
		else{
			lt=query1(tin[t],tin[t],1,1,sp)-c[t];
			lh=query1(tin[h],tin[h],1,1,sp)-c[h];
			l=query1(tin[t],tout[t],1,1,sp);
			//cout<<tin[t]<<' '<<tout[t]<<endl;
			//cout<<lt<<' '<<lh<<' '<<l<<endl;
			if(tin[t]<=tin[h]&&tout[h]<=tout[t])
				cout<<lh-lt<<endl;
			else
				cout<<l+lh-lt<<endl;
		}
	}
	return 0;
}