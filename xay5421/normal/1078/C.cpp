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
const int N=300005,P=998244353;
int n,f[N][3];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
void dfs(int k1,int k2){
	f[k1][0]=1;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs(to[i],k1);
		f[k1][2]=(f[k1][0]*(f[to[i]][0]+f[to[i]][1])+f[k1][1]*(f[to[i]][0]+f[to[i]][1])+f[k1][2]*(f[to[i]][0]+f[to[i]][2]*2))%P;
		f[k1][1]=(f[k1][0]*f[to[i]][2]+f[k1][1]*(f[to[i]][0]+f[to[i]][2]*2))%P;
		f[k1][0]=f[k1][0]*(f[to[i]][0]+f[to[i]][2])%P;
	}
}
signed main(){
	rd(n);
	rep(i,1,n-1){
		int k1,k2;rd(k1),rd(k2);
		ae(k1,k2),ae(k2,k1);
	}
	dfs(1,0);
	printf("%lld\n",(f[1][0]+f[1][2])%P);
	return 0;
}