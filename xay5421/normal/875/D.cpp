#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005;
int n,a[N],st[N],top,lc[N],rc[N],pre[N][31],nex[N][31];
LL ans;
void dfs(int u,int l,int r){
	if(!u)return;
	ans+=1LL*(u-l+1)*(r-u+1);
	int ll=l-1,rr=r+1;
	rep(i,0,30)if(~a[u]>>i&1)ll=max(ll,pre[u][i]),rr=min(rr,nex[u][i]);
	ans-=1LL*(u-ll)*(rr-u);
	dfs(lc[u],l,u-1);
	dfs(rc[u],u+1,r);
}
int main(){
	rd(n);
	rep(i,1,n){
		rd(a[i]);
		while(top&&a[i]>a[st[top]])lc[i]=st[top],--top;
		rc[st[top]]=i;
		st[++top]=i;
	}
	{
		vector<int>last(31,0);
		rep(i,1,n){
			rep(j,0,30){
				pre[i][j]=last[j];
				if(a[i]>>j&1)last[j]=i;
			}
		}
	}
	{
		vector<int>last(31,n+1);
		per(i,n,1){
			rep(j,0,30){
				nex[i][j]=last[j];
				if(a[i]>>j&1)last[j]=i;
			}
		}
	}
	dfs(rc[0],1,n);
	printf("%lld\n",ans);
	return 0;
}