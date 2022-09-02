// author: xay5421
// created: Wed Sep 22 17:35:20 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=3005,INF=0X3F3F3F3F;
int T,n,a[N],dp[N][N],nex[N],pre[N];
int sol(int l,int r){
	if(l>=r)return 0;
	if(dp[l][r]!=-1)return dp[l][r];
	if(a[l]==a[l+1])return dp[l][r]=sol(l+1,r)+1;
	int ret=sol(l+1,r);
	if(nex[l]<=r){
		for(int i=nex[l];i;i=nex[i])if(i<=r){
			ret=max(ret,sol(l+1,i-1)+sol(i,r)+1);
		}
	}
	return dp[l][r]=ret;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		map<int,int>lst;
		rep(i,1,n){
			if(lst.count(a[i])){
				pre[i]=lst[a[i]];
			}else{
				pre[i]=0;
			}
			lst[a[i]]=i;
		}
		lst.clear();
		per(i,n,1){
			if(lst.count(a[i])){
				nex[i]=lst[a[i]];
			}else{
				nex[i]=n+1;
			}
			lst[a[i]]=i;
		}
		rep(i,0,n)rep(j,0,n)dp[i][j]=-1;
		printf("%d\n",n-1-sol(1,n));
	}
	return 0;
}