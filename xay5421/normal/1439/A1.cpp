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
const int N=2005;
int T,n,m,a[N][N];
vector<vector<int> >v;
void ps(int aa,int b,int c,int d,int e,int f){
	a[aa][b]^=1;
	a[c][d]^=1;
	a[e][f]^=1;
	v.PB({aa,b,c,d,e,f});
}
void out(){
	pt(SZ(v),'\n');
	for(auto x:v){
		for(auto y:x)pt(y,' ');
		puts("");
	}
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	rep(_,1,T){
		v.clear();
		rd(n),rd(m);
		rep(i,1,n)rep(j,1,m){
			char c;while(!isdigit(c=getchar()));
			a[i][j]=c&1;
		}
		rep(i,1,n-2){
			rep(j,1,m-2){
				if(a[i][j]){
					ps(i,j,i+1,j,i+1,j+1);
				}
			}
		}
		rep(i,1,m-2){
			if(a[n-1][i]&&a[n][i]){
				ps(n-1,i,n,i,n-1,i+1);
			}else if(a[n-1][i]){
				ps(n-1,i,n-1,i+1,n,i+1);
			}else if(a[n][i]){
				ps(n,i,n-1,i+1,n,i+1);
			}
		}
		rep(i,1,n-2){
			if(a[i][m-1]&&a[i][m]){
				ps(i,m-1,i,m,i+1,m-1);
			}else if(a[i][m-1]){
				ps(i,m-1,i+1,m-1,i+1,m);
			}else if(a[i][m]){
				ps(i,m,i+1,m-1,i+1,m);
			}
		}
		while(1){
			int cnt=a[n-1][m-1]+a[n-1][m]+a[n][m-1]+a[n][m];
			if(cnt==0)break;
			if(cnt==3){
				vector<int>v;
				rep(i,0,1)rep(j,0,1){
					if(a[n-i][m-j])v.PB(n-i),v.PB(m-j);
				}
				ps(v[0],v[1],v[2],v[3],v[4],v[5]);
			}else if(cnt==1){
				vector<int>v;
				rep(i,0,1)rep(j,0,1){
					if(a[n-i][m-j])v.PB(n-i),v.PB(m-j);
				}
				rep(i,0,1)rep(j,0,1){
					if(!a[n-i][m-j])v.PB(n-i),v.PB(m-j);
				}
				ps(v[0],v[1],v[2],v[3],v[4],v[5]);
			}else if(cnt==2){
				vector<int>v;
				rep(i,0,1)rep(j,0,1){
					if(a[n-i][m-j])v.PB(n-i),v.PB(m-j);
				}
				v.pop_back(),v.pop_back();
				rep(i,0,1)rep(j,0,1){
					if(!a[n-i][m-j])v.PB(n-i),v.PB(m-j);
				}
				ps(v[0],v[1],v[2],v[3],v[4],v[5]);
			}else if(cnt==4){
				vector<int>v;
				rep(i,0,1)rep(j,0,1){
					if(a[n-i][m-j])v.PB(n-i),v.PB(m-j);
				}
				ps(v[0],v[1],v[2],v[3],v[4],v[5]);
			}
		}
		out();
	}
	return 0;
}