#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
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
const int N=200005,M=N*40;
int n,a[N],rt,ch[M][2],ind,ans;
void dfs(int k1,int k2){
	if(!ch[k1][0]&&!ch[k1][1]){
		ans=max(ans,k2+1);
		return;
	}
	if(ch[k1][0])dfs(ch[k1][0],k2+(ch[k1][1]>0));
	if(ch[k1][1])dfs(ch[k1][1],k2+(ch[k1][0]>0));
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rt=++ind;
	rep(i,1,n){
		int k1=rt;
		int x;
		rd(x);
		per(i,30,0){
			int d=x>>i&1;
			if(!ch[k1][d])ch[k1][d]=++ind;
			k1=ch[k1][d];
		}
	}
	dfs(1,0);
	pt(n-ans,'\n');
	return 0;
}