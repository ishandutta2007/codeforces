// author: xay5421
// created: Sun Dec  6 22:41:29 2020
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
const int N=305;
int T,n,cnt[3][2];
char s[N][N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		rd(n);
		rep(i,1,n){
			scanf("%s",s[i]+1);
			rep(j,1,n){
				if(s[i][j]!='.'){
					++cnt[(i+j)%3][s[i][j]=='X'];
				}
			}
		}
		int t=0;
		rep(i,1,2)if(cnt[i][1]<cnt[t][1])t=i;
		rep(i,1,n)rep(j,1,n)if(s[i][j]=='X'&&(i+j)%3==t)s[i][j]='O';
		rep(i,1,n)puts(s[i]+1);
	}
	return 0;
}