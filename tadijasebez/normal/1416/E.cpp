#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=500050;
namespace Treap{
	mt19937 rng(time(0));
	int ls[N],rs[N],tsz,tag[N],lzy1[N],lzy2[N],val[N],dp[N],mn[N],pri[N];
	void Upd1(int x,int f){if(x)val[x]+=f,lzy1[x]+=f;}
	void Upd2(int x,int f){if(x)dp[x]+=f,mn[x]+=f,lzy2[x]+=f;}
	void Flip(int x){if(x)tag[x]^=1,val[x]*=-1,lzy1[x]*=-1,swap(ls[x],rs[x]);}
	void Push(int x){
		if(tag[x])Flip(ls[x]),Flip(rs[x]),tag[x]=0;
		Upd1(ls[x],lzy1[x]),Upd1(rs[x],lzy1[x]),lzy1[x]=0;
		Upd2(ls[x],lzy2[x]),Upd2(rs[x],lzy2[x]),lzy2[x]=0;
	}
	void Pull(int x){mn[x]=dp[x];if(ls[x])ckmn(mn[x],mn[ls[x]]);if(rs[x])ckmn(mn[x],mn[rs[x]]);}
	void rot_l(int&c){int a=rs[c],b=ls[a];rs[c]=b;ls[a]=c;Pull(c);Pull(a);c=a;}
	void rot_r(int&c){int a=ls[c],b=rs[a];ls[c]=b;rs[a]=c;Pull(c);Pull(a);c=a;}
	void Split(int c,int&a,int&b,int v){
		if(!c)a=b=0;
		else{
			Push(c);
			if(val[c]<=v){
				a=c;Split(rs[c],rs[a],b,v);
				Pull(a);
			}else{
				b=c;Split(ls[c],a,ls[b],v);
				Pull(b);
			}
		}
	}
	int Make(int v,int d){tsz++;val[tsz]=v;dp[tsz]=mn[tsz]=d;pri[tsz]=rng();return tsz;}
	void Ins(int&c,int v,int d){
		if(!c)c=Make(v,d);
		else{
			Push(c);
			if(val[c]==v){
				ckmn(dp[c],d);
				Pull(c);
			}else if(val[c]<v){
				Ins(rs[c],v,d);
				if(pri[rs[c]]>pri[c])rot_l(c);
				else Pull(c);
			}else{
				Ins(ls[c],v,d);
				if(pri[ls[c]]>pri[c])rot_r(c);
				else Pull(c);
			}
		}
	}
	int Find(int c,int v){
		if(!c)return 1e9;
		Push(c);
		if(val[c]==v)return dp[c];
		if(val[c]<v)return Find(rs[c],v);
		else return Find(ls[c],v);
	}
}

const int M=6*N;
const ll inf=1e18;
int ls[M],rs[M],tsz,root[2],dprt;
ll mn[M],mx[M],lzy[M];
void Upd(int c,ll f){mn[c]+=f;mx[c]+=f;lzy[c]+=f;}
void Push(int c){Upd(ls[c],lzy[c]);Upd(rs[c],lzy[c]);lzy[c]=0;}
void Pull(int c){mn[c]=min(mn[ls[c]],mn[rs[c]]);mx[c]=max(mx[ls[c]],mx[rs[c]]);}
void Build(int&c,int ss,int se){
	c=++tsz;mn[c]=inf;mx[c]=-inf;
	if(ss==se)return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c,int ss,int se,int qi,int f){
	if(ss==se){mn[c]=mx[c]=f;return;}
	int mid=ss+se>>1;
	Push(c);
	if(qi<=mid)Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
	Pull(c);
}
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){Upd(c,f);return;}
	int mid=ss+se>>1;
	Push(c);
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	Pull(c);
}
pll mrg(pll a,pll b){return {min(a.first,b.first),max(a.second,b.second)};}
pll Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return {inf,-inf};
	if(qs<=ss&&qe>=se)return {mn[c],mx[c]};
	int mid=ss+se>>1;
	Push(c);
	return mrg(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
bool ok(int c0,int c1,int i,int x,ll m0,ll m1){
	ll hi,lo;
	if(i&1){
		hi=min(mn[c1],m1);
		lo=max(mx[c0],m0);
	}else{
		hi=-max(mx[c0],m0);
		lo=-min(mn[c1],m1);
	}
	ckmx(lo,(ll)0);
	lo++;hi--;
	return (x==-1&&lo<=hi)||(lo<=x&&hi>=x);
}
int Walk(int c0,int c1,int ss,int se,int i,int x,ll m0=-inf,ll m1=inf){
	if(ss==se)return ok(c0,c1,i,x,m0,m1)?ss:ss+1;
	int mid=ss+se>>1;
	Push(c0);Push(c1);
	if(ok(rs[c0],rs[c1],i,x,m0,m1))return Walk(ls[c0],ls[c1],ss,mid,i,x,max(m0,mx[rs[c0]]),min(m1,mn[rs[c1]]));
	else return Walk(rs[c0],rs[c1],mid+1,se,i,x,m0,m1);
}
int Find(int i,int x,int n){
	return Walk(root[0],root[1],1,n,i,x);
	/*int top=i,bot=1,mid,ans=i+1;
	while(top>=bot){
		mid=top+bot>>1;
		ll hi,lo;
		if(i&1){
			hi=Get(root[1],1,n,mid,i).first;
			lo=Get(root[0],1,n,mid,i).second;
		}else{
			hi=-Get(root[0],1,n,mid,i).second;
			lo=-Get(root[1],1,n,mid,i).first;
		}
		ckmx(lo,(ll)0);
		lo++;hi--;
		if((x==-1&&lo<=hi)||(lo<=x&&hi>=x))ans=mid,top=mid-1;
		else bot=mid+1;
	}
	return ans;*/
}

int a[N],dp[N];
int main(){
	for(int t=ri();t--;){
		int n=ri();
		ra(a,n);
		int treap=0;
		Build(root[0],1,n);
		Build(root[1],1,n);
		Build(dprt,1,n);
		dp[0]=0;
		for(int i=1;i<=n;i++){
			Set(dprt,1,n,i,dp[i-1]+1);
			Add(dprt,1,n,1,i,1);
			Set(root[i&1],1,n,i,0);
			int f=i%2==1?a[i]:-a[i];
			Add(root[0],1,n,1,i,f);
			Add(root[1],1,n,1,i,f);
			int ptr=Find(i,-1,n),hal;
			dp[i]=Get(dprt,1,n,ptr,i).first;
			if(a[i]%2==0){
				ptr=Find(i,a[i]/2,n);
				hal=Get(dprt,1,n,ptr,i).first-1;
				ckmn(hal,Treap::Find(treap,a[i]/2));
			}
			int p,q;
			Treap::Split(treap,p,q,a[i]-1);
			treap=p;
			Treap::Flip(treap);
			Treap::Upd1(treap,a[i]);
			Treap::Upd2(treap,1);
			if(a[i]%2==0)Treap::Ins(treap,a[i]/2,hal);
			if(treap)ckmn(dp[i],Treap::mn[treap]);
		}
		printf("%i\n",dp[n]);
	}
	return 0;
}