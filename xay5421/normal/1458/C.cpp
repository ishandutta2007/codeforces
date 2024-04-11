// author: xay5421
// created: Sat Dec 19 17:54:53 2020
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
const int N=1005;
int T,n,m,a[N][N],b[N][N];
char s[100005];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,0,n-1)rep(j,0,n-1){
			rd(a[i][j]);
			--a[i][j];
		}
		int id[3]={0,1,2};
		int w[3]={0,0,0};
		scanf("%s",s+1);
		rep(i,1,m){
			if(s[i]=='R'){
				++w[1]%=n;
			}
			if(s[i]=='L'){
				(w[1]+=n-1)%=n;
			}
			if(s[i]=='D'){
				++w[0]%=n;
			}
			if(s[i]=='U'){
				(w[0]+=n-1)%=n;
			}
			if(s[i]=='C')swap(id[0],id[2]),swap(w[0],w[2]);
			if(s[i]=='I')swap(id[1],id[2]),swap(w[1],w[2]);
		}
		rep(i,0,n-1)rep(j,0,n-1)b[i][j]=0;
		rep(i,0,n-1)rep(j,0,n-1){
			int x=id[0]==0?i:id[0]==1?j:a[i][j];
			int y=id[1]==0?i:id[1]==1?j:a[i][j];
			int z=id[2]==0?i:id[2]==1?j:a[i][j];
			(x+=w[0])%=n;
			(y+=w[1])%=n;
			(z+=w[2])%=n;
			b[x][y]=z;
		}
		rep(i,0,n-1){
			rep(j,0,n-1)pt(b[i][j]+1,' ');
			puts("");
		}
		puts("");
	}
	return 0;
}