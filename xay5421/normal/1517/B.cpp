// author: xay5421
// created: Fri Apr 23 22:39:55 2021
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
const int N=105;
int T,n,m,b[N][N];
bool vis[N][N];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		vector<pair<int,pair<int,int> > >a;
		rep(i,1,n)rep(j,1,m)rd(b[i][j]),vis[i][j]=0,a.push_back(make_pair(b[i][j],make_pair(i,j)));
		sort(a.begin(),a.end());
		int cur=0;
		for(auto x:a)if(++cur<=m)vis[x.Y.X][x.Y.Y]=1;
		int now=1;
		rep(i,1,n){
			sort(b[i]+1,b[i]+1+m);
			int he=1,ta=m;
			rep(j,1,now-1)pt(b[i][ta--],' ');
			rep(j,now,m)pt(b[i][he++],' ');
			rep(j,1,m)now+=vis[i][j];
			puts("");
		}
	}
	return 0;
}