// author: xay5421
// created: Sun Jul 11 22:00:56 2021
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
const int N=100005;
int T,n,a[N],id[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),id[i]=i;
		sort(id+1,id+1+n,[&](int x,int y){return a[x]<a[y];});
		bool err=0;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&a[id[i]]==a[id[j]])++j;
			int cnt[2]={0,0};
			rep(k,i,j-1)++cnt[id[k]&1],--cnt[k&1];
			if(cnt[0]!=0||cnt[1]!=0){
				err=1;
			}
		}
		if(err)puts("NO");else puts("YES");
	}
	return 0;
}