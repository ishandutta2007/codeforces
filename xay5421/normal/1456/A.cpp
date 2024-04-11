// author: xay5421
// created: Sun Nov 29 15:19:59 2020
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
const int N=100005,INFLL=0X3F3F3F3F3F3F3F3FLL;
int T,n,p,K,tt[N],w[N];
char s[N];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(p),rd(K);
		scanf("%s",s+1);
		rep(i,1,n)s[i]-='0';
		rep(i,1,n){
			++w[i%K];
			tt[i%K]+=s[i];
		}
		rep(i,1,p-1){
			--w[i%K];
			tt[i%K]-=s[i];
		}
		int y,x;rd(y),rd(x);
		int ans=INFLL;
		rep(i,1,n-p+1){
			int tem=i+p-1,sum=(i-1)*x;
			sum+=(w[tem%K]-tt[tem%K])*y;
			--w[tem%K];
			tt[tem%K]-=s[tem];
			ans=min(ans,sum);
		}
		pt(ans,'\n');
	}
	return 0;
}