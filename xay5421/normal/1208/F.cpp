#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
const int N=1000005;
template<typename T>T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
int n,a[N],ans,cnt[(1<<21)+5];
void dfs(int b,int x){
	if(cnt[x]>1)return;
	if(b<0){++cnt[x];return;}
	dfs(b-1,x);if(x>>b&1)dfs(b-1,x^(1<<b));
}
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	per(i,n,1){
		int b=0;
		for(int j=20;j>=0;--j)if(~a[i]>>j&1){
			if(cnt[b|(1<<j)]>1)b|=(1<<j);
		}
		if(i<n-1)ans=max(ans,a[i]|b);
		dfs(20,a[i]);
	}
	printf("%d\n",ans); 
	return 0;
}