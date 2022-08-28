//CF1534G
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
const int N = 1600016;
int n,rt,tot,val[N],ls[N],rs[N],sz[N],len[N],t[N],w[N];
void ch(int k,int dw){
	if(k)
		t[k]+=dw,w[k]+=dw;
}
void pd(int k){
	if(w[k]){
		ch(ls[k],w[k]);
		ch(rs[k],w[k]);
		w[k]=0;
	}
}
void pu(int k){
	len[k]=len[ls[k]]+len[rs[k]]+sz[k];
}
struct tri{
	int l,h,r;
	tri(int x=0,int y=0,int z=0){
		l=x,h=y,r=z;
	}
};
tri split3(int k,int x){
	if(!k)
		return tri(0,0,0);
	pd(k);
	tri p;
	int o=len[ls[k]];
	if(o<x&&x<o+sz[k]){
		p=tri(ls[k],k,rs[k]);
		ls[k]=0;
		rs[k]=0;
		return p;
	}
	if(o>=x){
		p=split3(ls[k],x);
		ls[k]=p.r;
		p.r=k;
	}
	else{
		p=split3(rs[k],x-o-sz[k]);
		rs[k]=p.l;
		p.l=k;
	}
	pu(k);
	return p;
}
pair<int,int> split2(int k){
	if(!k)
		return make_pair(0,0);
	pd(k);
	pair<int,int> p;
	if(t[k]>=0){
		p=split2(ls[k]);
		ls[k]=p.second;
		p.second=k;
	}
	else{
		p=split2(rs[k]);
		rs[k]=p.first;
		p.first=k;
	}
	pu(k);
	return p;
}
int merge(int k1,int k2){
	if(!k1||!k2)
		return k1+k2;
	pd(k1),pd(k2);
	if(val[k1]<val[k2]){
		rs[k1]=merge(rs[k1],k2);
		pu(k1);
		return k1;
	}
	else{
		ls[k2]=merge(k1,ls[k2]);
		pu(k2);
		return k2;
	}
}
void go1(int x){
	if(!x)
		return;
	int k=++tot;
	pair<int,int> p;
	p=split2(rt);
	sz[k]=x;
	len[k]=x;
	rt=merge(merge(p.first,k),p.second);
	/*cout<<rt<<endl;
	for(int i=1;i<=tot;i++)
		cout<<i<<' '<<ls[i]<<' '<<rs[i]<<' '<<sz[i]<<' '<<t[i]<<' '<<w[i]<<endl;*/
}
void go2(int x){
	tri p;
	int k,u;
	p=split3(rt,x);//cout<<p.l<<' '<<p.h<<' '<<p.r<<endl;
	u=p.h;
	if(u){
		k=++tot;
		t[k]=t[u];
		w[k]=w[u];
		sz[k]=x-len[p.l];
		len[k]=sz[k];
		sz[u]-=sz[k];
		len[u]=sz[u];
		k=merge(p.l,k);
		u=merge(u,p.r);
	}
	else{
		k=p.l;
		u=p.r;
	}
	ch(k,-1);
	ch(u,1);//cout<<k<<' '<<u<<endl;
	rt=merge(k,u);
	/*cout<<rt<<endl;
	for(int i=1;i<=tot;i++)
		cout<<i<<' '<<ls[i]<<' '<<rs[i]<<' '<<sz[i]<<' '<<t[i]<<' '<<w[i]<<endl;*/
}
int x[N],y[N];
LL s,ans;
void dfs(int k){
	if(!k)
		return;
	pd(k);
	dfs(ls[k]);
	s+=(LL)t[k]*sz[k];
	ans=min(ans,s);
	dfs(rs[k]);
}
pair<int,int> p[N];
int main()
{
	srand(2333);
	int i,j,o;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
		p[i]=make_pair(x[i]+y[i],i);
	}
	for(i=1;i<=n*2;i++)
		val[i]=rand()<<15|rand();
	sort(p+1,p+n+1);
	o=0;
	for(i=1;i<=n;i++){
		j=p[i].second;
		go1(x[j]+y[j]-o);
		o=x[j]+y[j];
		go2(x[j]);
		s+=x[j];
	}
	ans=s;
	dfs(rt);
	cout<<ans;
	return 0;
}