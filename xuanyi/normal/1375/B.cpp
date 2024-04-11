#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=305;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int T,n,m,a[N][N],b[N][N];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)rep(j,1,m)rd(a[i][j]);
		bool flg=0;
		rep(i,1,n){
			rep(j,1,m){
				int tot=0;
				rep(k,0,3){
					int ni=i+dx[k],nj=j+dy[k];
					if(ni>=1&&nj>=1&&ni<=n&&nj<=m){
						++tot;
					}
				}
				if(tot<a[i][j]){
					flg=1;
				}
				b[i][j]=tot;
			}
		}
		if(flg){
			puts("NO");
		}else{
			puts("YES");
			rep(i,1,n)rep(j,1,m)pt(b[i][j],j==m?'\n':' ');
		}
	}
	return 0;
}