// author: xay5421
// created: Sun May 30 22:21:40 2021
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
int T,n,m;
char s[N],t[N];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		scanf("%s",s+1);
		s[0]=s[n+1]='0';
		rep(_,1,m){
			bool flg=0;
			rep(i,0,n+1)t[i]=s[i];
			rep(i,1,n){
				if(s[i]=='0'){
					if((t[i-1]=='1'&&t[i+1]!='1')||(t[i-1]!='1'&&t[i+1]=='1')){
						s[i]='1';
						flg=1;
					}
				}else s[i]='1';
			}
			if(!flg)break;
		}
		rep(i,1,n)putchar(s[i]);
		puts("");
	}
	return 0;
}