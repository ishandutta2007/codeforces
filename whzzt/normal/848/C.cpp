#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define lowbit(x) ((x)&-(x))

using namespace std;
typedef pair<int,int>pi;
typedef long long ll;

const int N=100005,M=10000005;

int ls[M],rs[M],rt[N],n,a[N],m,ndc;
set<int>dat[N];
ll sum[M];
void update(int&x,int l,int r,int p,int u){
	if(!x)x=++ndc;sum[x]+=u;if(l==r)return;int mid=(l+r)>>1;
	if(p<=mid)update(ls[x],l,mid,p,u);else update(rs[x],mid+1,r,p,u);
}
ll ask(int&x,int l,int r,int s,int t){
	if(!x||l==s&&r==t)return sum[x];int mid=(l+r)>>1;
	if(t<=mid)return ask(ls[x],l,mid,s,t);
	if(s>mid)return ask(rs[x],mid+1,r,s,t);
	return ask(ls[x],l,mid,s,mid)+ask(rs[x],mid+1,r,mid+1,t);
}
void modify(int x,int y,int u){while(x<=n)update(rt[x],1,n,y,u),x+=lowbit(x);}
ll query(int x,int y){
	ll ret=0;
	while(x)ret+=ask(rt[x],1,n,1,y),x-=lowbit(x);
	return ret;
}
void add(int p,int x){
	dat[p].insert(x);
	auto it=dat[p].find(x),pre=it,suf=it;
	bool f1=false,f2=false;
	if(pre!=dat[p].begin())--pre,modify(*pre,x,x-*pre),f1=1;
	++suf;
	if(suf!=dat[p].end())modify(x,*suf,*suf-x),f2=1;
	if(f1&&f2)modify(*pre,*suf,-(*suf-*pre));
}
void del(int p,int x){
	auto it=dat[p].find(x),pre=it,suf=it;
	bool f1=false,f2=false;
	if(pre!=dat[p].begin())--pre,modify(*pre,x,-(x-*pre)),f1=1;
	++suf;
	if(suf!=dat[p].end())modify(x,*suf,-(*suf-x)),f2=1;
	if(f1&&f2)modify(*pre,*suf,*suf-*pre);
	dat[p].erase(x);
}

int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),add(a[i],i);
	for(int i=1,o,u,v;i<=m;i++){
		scanf("%d%d%d",&o,&u,&v);
		if(o==1)del(a[u],u),a[u]=v,add(a[u],u);
		else printf("%lld\n",query(n,v)-query(u-1,v));
	}
	return 0;
}