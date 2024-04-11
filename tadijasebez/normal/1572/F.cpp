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

const int N=200050;
const int M=2*N;

namespace SegLazy{
	int ls[M],rs[M],tsz,root;
	ll sum[M],lzy[M];
	void Build(int&c,int ss,int se){
		c=++tsz;
		sum[c]=se-ss+1;lzy[c]=0;
		if(ss==se)return;
		int mid=ss+se>>1;
		Build(ls[c],ss,mid);
		Build(rs[c],mid+1,se);
	}
	void upd(int c,int ss,int se,ll x){sum[c]+=x*(se-ss+1);lzy[c]+=x;}
	void push(int c,int ss,int se){
		if(!lzy[c])return;
		int mid=ss+se>>1;
		upd(ls[c],ss,mid,lzy[c]);
		upd(rs[c],mid+1,se,lzy[c]);
		lzy[c]=0;
	}
	void Add(int c,int ss,int se,int qs,int qe,ll x){
		if(qs>qe||qs>se||ss>qe)return;
		if(qs<=ss&&qe>=se){upd(c,ss,se,x);return;}
		int mid=ss+se>>1;
		push(c,ss,se);
		Add(ls[c],ss,mid,qs,qe,x);
		Add(rs[c],mid+1,se,qs,qe,x);
		sum[c]=sum[ls[c]]+sum[rs[c]];
	}
	ll Get(int c,int ss,int se,int qs,int qe){
		if(qs>qe||qs>se||ss>qe)return 0;
		if(qs<=ss&&qe>=se)return sum[c];
		int mid=ss+se>>1;
		push(c,ss,se);
		return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
	}
}

int n,q;
int ls[M],rs[M],tsz,root,mx[M],smx[M],cnt[M],lzy[M];
void Build(int&c,int ss,int se){
	c=++tsz;
	mx[c]=se;
	smx[c]=se-1;
	cnt[c]=1;
	lzy[c]=n+1;
	if(ss==se){
		smx[c]=0;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void upd(int c,int x){
	if(mx[c]>x){
		mx[c]=x;
		lzy[c]=x;
	}
}
void push(int c){
	if(lzy[c]!=n+1){
		upd(ls[c],lzy[c]);
		upd(rs[c],lzy[c]);
		lzy[c]=n+1;
	}
}
void pull(int c){
	if(mx[ls[c]]>mx[rs[c]]){
		mx[c]=mx[ls[c]];
		smx[c]=max(smx[ls[c]],mx[rs[c]]);
		cnt[c]=cnt[ls[c]];
	}else if(mx[rs[c]]>mx[ls[c]]){
		mx[c]=mx[rs[c]];
		smx[c]=max(mx[ls[c]],smx[rs[c]]);
		cnt[c]=cnt[rs[c]];
	}else{
		mx[c]=mx[ls[c]];
		smx[c]=max(smx[ls[c]],smx[rs[c]]);
		cnt[c]=cnt[ls[c]]+cnt[rs[c]];
	}
}
void Set(int c,int ss,int se,int qi,int x){
	if(ss==se){
		//printf("mx:%i qi:%i\n",mx[c],qi);
		SegLazy::Add(SegLazy::root,1,n,qi,mx[c],-1);
		SegLazy::Add(SegLazy::root,1,n,qi,x,1);
		mx[c]=x;
		smx[c]=0;
		cnt[c]=1;
		return;
	}
	int mid=ss+se>>1;
	push(c);
	if(qi<=mid)Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	pull(c);
}
void Min(int c,int ss,int se,int qs,int qe,int x){
	if(qs>qe||qs>se||ss>qe||mx[c]<=x)return;
	if(qs<=ss&qe>=se&&smx[c]<x){
		//printf("ss:%i se:%i mx:%i cnt:%i\n",ss,se,mx[c],cnt[c]);
		SegLazy::Add(SegLazy::root,1,n,x+1,mx[c],-cnt[c]);
		upd(c,x);
		return;
	}
	int mid=ss+se>>1;
	push(c);
	Min(ls[c],ss,mid,qs,qe,x);
	Min(rs[c],mid+1,se,qs,qe,x);
	pull(c);
}
int main(){
	scanf("%i %i",&n,&q);
	SegLazy::Build(SegLazy::root,1,n);
	Build(root,1,n);
	while(q--){
		int t,a,b;
		scanf("%i %i %i",&t,&a,&b);
		if(t==1){
			Set(root,1,n,a,b);
			//printf(":D\n");
			Min(root,1,n,1,a-1,a-1);
		}else{
			printf("%lld\n",SegLazy::Get(SegLazy::root,1,n,a,b));
		}
	}
	return 0;
}