#include<bits/stdc++.h>
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=500005;
int n,m,le[N];
LL t[N],ans[N];
void upd(int k1,int k2){
	for(int i=k1;i<N;i+=i&-i)t[i]+=k2;
}
LL qry(int k1){
	LL k2=0;
	for(int i=k1;i;i&=i-1)k2+=t[i];
	return k2;
}
LL qry(int l,int r){
	return qry(r)-(l==0?0:qry(l-1));
}
int getl(int k1){
	int s=qry(k1);
	k1=0;
	for(int i=(1<<20);i;i>>=1){
		if(k1+i<N&&t[k1+i]<s){
			k1+=i;
			s-=t[k1];
		}
	}
	return k1;
}
struct data{
	int o,k1,k2;
	void init(){
		while(!isalpha(o=getchar()));
		scanf("%d",&k1);
		if(o=='U'||o=='M')scanf("%d",&k2);
	}
}q[N];
vector<int>ma[N*2],mb[N*2],que[N];
struct tree{
	int ind,lc[N*2],rc[N*2],fa[N*2],sz[N*2];
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	void init(int n){
		ind=n;
		rep(i,1,n)fa[i]=i,sz[i]=1;
	}
	void mer(int k1,int k2){
		++ind;
		k1=fd(k1),k2=fd(k2);
		fa[k1]=fa[k2]=fa[ind]=ind;
		lc[ind]=k1,rc[ind]=k2;
		sz[ind]=sz[k1]+sz[k2];
	}
	void dfs1(int k1){
		for(auto x:mb[k1])upd(x,1);
		if(k1<=n){
			for(auto x:que[k1])le[x]=getl(x);
		}else{
			dfs1(lc[k1]);
			dfs1(rc[k1]);
		}
		for(auto x:mb[k1])upd(x,-1);
	}
	void dfs2(int k1){
		for(auto x:ma[k1])upd(x,sz[k1]);
		if(k1<=n){
			for(auto x:que[k1])ans[x]=qry(le[x]+1,x);
		}else{
			dfs2(lc[k1]);
			dfs2(rc[k1]);
		}
		for(auto x:ma[k1])upd(x,-sz[k1]);
	}
}A,B;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)q[i].init();
	A.init(n),B.init(n);
	rep(i,1,m){
		switch(q[i].o){
			case 'U':
				A.mer(q[i].k1,q[i].k2);
				break;
			case 'M':
				B.mer(q[i].k1,q[i].k2);
				break;
			case 'A':
				q[i].k1=A.fd(q[i].k1);
				ma[q[i].k1].PB(i);
				break;
			case 'Z':
				q[i].k1=B.fd(q[i].k1);
				mb[q[i].k1].PB(i);
				break;
			case 'Q':
				que[q[i].k1].PB(i);
		}
	}
	rep(i,1,B.ind)if(B.fd(i)==i)B.dfs1(i);
	rep(i,1,A.ind)if(A.fd(i)==i)A.dfs2(i);
	rep(i,1,m){
		if(q[i].o=='Q')printf("%lld\n",ans[i]);
	}
	return 0;
}