#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
const int N=20005,INF=0X3F3F3F3F;
int n,K,a[N],dp[N],old_dp[N];
int F(int i,int k){
	return old_dp[i]-k*(i-1);
}
struct convex{
	deque<int>v;
	int ask(int k){ // min(y-k*x)
		int l=0,r=SZ(v)-2,ans=F(v.back(),k);
		while(l<=r){
			int mid=(l+r)>>1;
			int k1=F(v[mid],k),k2=F(v[mid+1],k);
			if(k1<k2){
				umin(ans,k1);
				r=mid-1;
			}else{
				umin(ans,k2);
				l=mid+1;
			}
		}
		return ans;
	}
}hull[N];
LL cross(int a,int b,int c,int d){return 1LL*a*d-1LL*b*c;}
void mer(convex&lhs,convex&rhs){ // rhs.push_front(lhs)
	if(SZ(lhs.v)<SZ(rhs.v)){
		for(int i=SZ(lhs.v)-1,x;i>=0;--i){
			x=lhs.v[i];
			while(SZ(rhs.v)>1&&cross(rhs.v[0]-rhs.v[1],old_dp[rhs.v[0]]-old_dp[rhs.v[1]],x-rhs.v[1],old_dp[x]-old_dp[rhs.v[1]])>=0)rhs.v.pop_front();
			rhs.v.push_front(x);
		}
	}else{
		for(auto&x:rhs.v){
			int tail=SZ(lhs.v)-1;
			while(SZ(lhs.v)>1&&cross(lhs.v[tail]-lhs.v[tail-1],old_dp[lhs.v[tail]]-old_dp[lhs.v[tail-1]],x-lhs.v[tail-1],old_dp[x]-old_dp[lhs.v[tail-1]])<=0)lhs.v.pop_back(),--tail;
			lhs.v.pb(x);
		}
		rhs=move(lhs);
	}
}
const int M=N*40;
int ind,root[N],lc[M],rc[M],kk[M],bb[M];
int new_node(int u){
	++ind;
	lc[ind]=lc[u];
	rc[ind]=rc[u];
	kk[ind]=kk[u];
	bb[ind]=bb[u];
	return ind;
}
int new_node(int k,int b){
	++ind;
	lc[ind]=0;
	rc[ind]=0;
	kk[ind]=k;
	bb[ind]=b;
	return ind;
}
void mdf(int&u,int l,int r,int k,int b){
	if(!u){
		u=new_node(k,b);
		return;
	}
	u=new_node(u);
	int mid=(l+r)>>1;
	if(k*mid+b<kk[u]*mid+bb[u]){
		swap(k,kk[u]);
		swap(b,bb[u]);
	}
	if(l==r)return;
	if(k<kk[u]){
		mdf(rc[u],mid+1,r,k,b);
	}
	if(k>kk[u]){
		mdf(lc[u],l,mid,k,b);
	}
}
int ask(int u,int l,int r,int x){
	if(!u)return INF;
	int mid=(l+r)>>1;
	if(x<=mid){
		return min(kk[u]*x+bb[u],ask(lc[u],l,mid,x));
	}else{
		return min(kk[u]*x+bb[u],ask(rc[u],mid+1,r,x));
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&K);
	rep(i,1,n)scanf("%d",&a[i]);
	int pre_max=0;
	rep(i,1,n){
		umax(pre_max,a[i]);
		dp[i+1]=pre_max*i;
	}
	static int st[N],top;
	rep(_,2,K){
		rep(i,_,n+1)old_dp[i]=dp[i];
		top=0,ind=0;
		rep(i,_,n){
			hull[i].v={i};
			while(top&&a[i]>=a[st[top]]){
				mer(hull[st[top--]],hull[i]);
			}
			root[i]=root[st[top]];
			int val=hull[i].ask(a[i]);
			mdf(root[i],1,n,a[i],val);
			dp[i+1]=ask(root[i],1,n,i);
			st[++top]=i;
		}
		//rep(i,1,n+1)D("dp[%d]=%d\n",i,dp[i]);
		//D("\n");
	}
	printf("%d\n",dp[n+1]);
	return 0;
}