//CF1528C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
const int W = 1<<20;
int n,m,a[N],b[N],d[N],q3[N],q4[N];
vector<int> v[N],v2[N],q[N],q2[N];
void dfs2(int u){
	int i,x;
	a[u]=++m;
	for(i=0;i<v2[u].size();i++){
		x=v2[u][i];
		d[x]=d[u]+1;
		dfs2(x);
	}
	b[u]=m;
}
int cur;
int t[W],t2[W];
int mx(int x,int y){
	if(d[x]>d[y])
		return x;
	return y;
}
void ch(int k,int x){
	q[cur].push_back(k);
	q2[cur].push_back(t[k]);
	t[k]=mx(t[k],x);
}
void modify(int L,int R,int X,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		ch(k,X);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,X,k<<1,l,h);
	if(h<R)
		modify(L,R,X,k<<1|1,h+1,r);
}
int query(int P,int k=1,int l=1,int r=n){
	if(l==r)
		return t[k];
	int h=l+r>>1;
	if(P<=h)
		return mx(t[k],query(P,k<<1,l,h));
	return mx(t[k],query(P,k<<1|1,h+1,r));
}
void ad2(int x,int y){
	while(x<=n){
		t2[x]+=y;
		x+=x&-x;
	}
}
int qu2(int x){
	int y=0;
	while(x){
		y+=t2[x];
		x-=x&-x;
	}
	return y;
}
int s,c[N];
void go(int u){
	int x;
	cur=u;
	ad2(a[u],1);
	if(qu2(b[u])-qu2(a[u]-1)>1){
		return;
	}
	x=query(a[u]);
	if(x&&c[x]){
		q3[u]=x;
		c[x]=0;
		c[u]=1;
	}
	else{
		s++;
		c[u]=1;
	}
	q4[u]=1;
	modify(a[u],b[u],u);
}
void rem(int u){
	int i;
	ad2(a[u],-1);
	if(q4[u]){
		for(i=0;i<q[u].size();i++)
			t[q[u][i]]=q2[u][i];
		c[u]=0;
		if(q3[u]){
			c[q3[u]]=1;
		}
		else
			s--;
	}
}
int ans;
void dfs1(int u){
	int i,x;
	go(u);
	ans=max(ans,s);
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		dfs1(x);
	}
	rem(u);
}
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=2;i<=n;i++){
			scanf("%d",&x);
			v[x].push_back(i);
		}
		for(i=2;i<=n;i++){
			scanf("%d",&x);
			v2[x].push_back(i);
		}
		m=0;
		d[1]=1;
		dfs2(1);
		dfs1(1);
		printf("%d\n",ans);
		ans=0;
		for(i=0;i<=n;i++){
			v[i].clear();
			v2[i].clear();
			q[i].clear();
			q2[i].clear();
			t2[i]=0;
			q3[i]=0;
			q4[i]=0;
		}
		for(i=0;i<N&&i<=n*4;i++)
			t[i]=0;
	}
	return 0;
}