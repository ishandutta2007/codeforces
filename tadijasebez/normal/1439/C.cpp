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
int ls[M],rs[M],tsz,root;
ll sum[M],mn[M],lzy[M];
void pull(int c){
	sum[c]=sum[ls[c]]+sum[rs[c]];
	mn[c]=mn[rs[c]];
}
void Build(int&c,int ss,int se,int a[]){
	c=++tsz;lzy[c]=-1;
	if(ss==se){sum[c]=mn[c]=a[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid,a);
	Build(rs[c],mid+1,se,a);
	pull(c);
}
void upd(int c,int ss,int se,int x){
	lzy[c]=x;
	sum[c]=(ll)x*(se-ss+1);
	mn[c]=x;
}
void push(int c,int ss,int se){
	int mid=ss+se>>1;
	if(lzy[c]!=-1){
		upd(ls[c],ss,mid,lzy[c]);
		upd(rs[c],mid+1,se,lzy[c]);
		lzy[c]=-1;
	}
}
void Set(int c,int ss,int se,int qs,int qe,int x){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){upd(c,ss,se,x);return;}
	int mid=ss+se>>1;
	push(c,ss,se);
	Set(ls[c],ss,mid,qs,qe,x);
	Set(rs[c],mid+1,se,qs,qe,x);
	pull(c);
}
ll Sum(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return sum[c];
	int mid=ss+se>>1;
	push(c,ss,se);
	return Sum(ls[c],ss,mid,qs,qe)+Sum(rs[c],mid+1,se,qs,qe);
}
int Walk(int c,int ss,int se,ll k){
	if(ss==se)return k>=sum[c]?ss+1:ss;
	push(c,ss,se);
	int mid=ss+se>>1;
	if(sum[ls[c]]<=k)return Walk(rs[c],mid+1,se,k-sum[ls[c]]);
	else return Walk(ls[c],ss,mid,k);
}
int Srch(int c,int ss,int se,int k){
	if(ss==se)return k<mn[c]?ss+1:ss;
	push(c,ss,se);
	int mid=ss+se>>1;
	if(mn[ls[c]]>k)return Srch(rs[c],mid+1,se,k);
	else return Srch(ls[c],ss,mid,k);
}
int a[N];
int main(){
	int n,q;rd(n,q);
	ra(a,n);
	Build(root,1,n,a);
	while(q--){
		int t,x,y;rd(t,x,y);
		if(t==1){
			int L=Srch(root,1,n,y);
			int R=x;
			Set(root,1,n,L,R,y);
		}else{
			int ptr=x,ans=0;
			while(1){
				ptr=max(ptr,Srch(root,1,n,y));
				if(ptr>n)break;
				int nxt=Walk(root,1,n,y+Sum(root,1,n,1,ptr-1));
				ans+=nxt-ptr;
				y-=Sum(root,1,n,ptr,nxt-1);
				//printf("%i %i %i\n",ptr,nxt,y);
				ptr=nxt;
			}
			printf("%i\n",ans);
		}
		//for(int i=1;i<=n;i++)printf("%lld ",Sum(root,1,n,i,i));
		//printf("\n");
	}
	return 0;
}