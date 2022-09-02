// author: xay5421
// created: Sun Mar 21 21:49:12 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005,K=20;
int n,h[N],w[N],f[N][K],lg[N];
int mymin(int x,int y){
	return h[x]<h[y]?x:y;
}
int qry(int l,int r){
	int x=lg[r-l+1];
	return mymin(f[l][x],f[r-(1<<x)+1][x]);
}
struct node{
	LL A,L,R,M;
};
node sol(int l,int r){
	if(l>r){
		return(node){0,0,0,0};
	}
	int mid=qry(l,r);
	node a=sol(l,mid-1),b=sol(mid+1,r);
	node c;
	c.A=c.L=c.R=c.M=-1e18;
	c.A=a.L+b.R+w[mid];
	c.L=max({a.L,a.L+w[mid]+b.M,0LL});
	c.R=max({b.R,b.R+w[mid]+a.M,0LL});
	c.M=max({a.M,b.M,w[mid]+a.M+b.M,0LL});
	return c;
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	rd(n);
	rep(i,1,n)rd(h[i]);
	rep(i,1,n)rd(w[i]);
	rep(i,1,n)f[i][0]=i;
	rep(j,1,K)rep(i,1,n-(1<<j)+1){
		f[i][j]=mymin(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	node ans=sol(1,n);
	printf("%lld\n",ans.A);
	return 0;
}