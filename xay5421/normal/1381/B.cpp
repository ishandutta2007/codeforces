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
const int N=4005;
int T,n,p[N],len,q[N],f[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n*2)rd(p[i]);
		len=0;
		for(int i=1,j;i<=n*2;i=j){
			j=i+1;
			while(j<=n*2&&p[j]<p[i])++j;
			q[++len]=j-i;
		}
		rep(i,0,n*2)f[i]=0;
		f[0]=1;
		rep(i,1,len){
			per(j,N-1,q[i])f[j]|=f[j-q[i]];
		}
		puts(f[n]?"YES":"NO");
	}
	return 0;
}