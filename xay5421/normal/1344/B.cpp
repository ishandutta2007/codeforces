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
int n,m,fa[N*N];
char s[N][N];
bool pd1[N],pd2[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
signed main(){
	rd(n),rd(m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m){
		if(s[i][j]=='#'){
			pd1[i]=1,pd2[j]=1;
		}
	}
	int hav1=count(pd1+1,pd1+1+n,0);
	int hav2=count(pd2+1,pd2+1+m,0);
	rep(i,1,n){
		int flg=-1;
		int err=0;
		rep(j,1,m){
			if(flg==-1&&s[i][j]=='#'){
				flg=1;
			}
			if(flg==1&&s[i][j]=='.'){
				flg=0;
			}
			if(flg==0&&s[i][j]=='#'){
				err=1;
			}
		}
		if(err)puts("-1"),exit(0);
		if(flg==-1){
			if(!hav2){
				puts("-1"),exit(0);
			}
		}
	}
	rep(j,1,m){
		int flg=-1;
		int err=0;
		rep(i,1,n){
			if(flg==-1&&s[i][j]=='#'){
				flg=1;
			}
			if(flg==1&&s[i][j]=='.'){
				flg=0;
			}
			if(flg==0&&s[i][j]=='#'){
				err=1;
			}
		}
		if(err)puts("-1"),exit(0);
		if(flg==-1){
			if(!hav1){
				puts("-1"),exit(0);
			}
		}
	}
	rep(i,1,N*N-1)fa[i]=i;
	auto zip=[&](int x,int y){return (x-1)*m+y;};
	auto ae=[&](int k1,int k2){
		fa[fd(k1)]=fd(k2);
	};
	rep(i,1,n)rep(j,1,m-1){
		if(s[i][j]=='#'&&s[i][j+1]=='#'){
			ae(zip(i,j),zip(i,j+1));
		}
	}
	rep(i,1,n-1)rep(j,1,m){
		if(s[i][j]=='#'&&s[i+1][j]=='#'){
			ae(zip(i,j),zip(i+1,j));
		}
	}
	int ans=0;
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='#'&&fd(zip(i,j))==zip(i,j))++ans;
	pt(ans,'\n');
	return 0;
}