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
const int N=200005,P=998244353;
int T,n,K,a[N],b[N],p[N],pre[N],nxt[N];
int ban[N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(K);
		rep(i,1,n)rd(a[i]),p[a[i]]=i;
		rep(i,1,K)rd(b[i]),b[i]=p[b[i]];
		rep(i,0,n+1)ban[i]=0;
		ban[0]=ban[n+1]=1;
		rep(i,1,n)pre[i]=i-1,nxt[i]=i+1;
		per(i,K,1)ban[b[i]]=1;
		int ans=1;
		rep(i,1,K){
			if(ban[pre[b[i]]]+ban[nxt[b[i]]]==2){
				ans=0;
				break;
			}
			if(ban[pre[b[i]]]||ban[nxt[b[i]]]){
				
			}else{
				ans=ans*2%P;
			}
			ban[b[i]]=0;
		}
		pt(ans,'\n');
	}
	return 0;
}