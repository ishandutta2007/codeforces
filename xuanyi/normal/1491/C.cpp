// author: xay5421
// created: Sun Feb 28 21:39:12 2021
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
const int N=5005;
const int INFLL=1e18;
int T,n,a[N],cnt[N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),cnt[i]=0;
		int ans=0;
		rep(i,1,n){
			if(a[i]>1){
				if(a[i]-cnt[i]-1<=0){
					per(j,min(n,i+a[i]),i+2){
						++cnt[j];
					}
					cnt[i]-=a[i]-1;
					cnt[i+1]=min(cnt[i+1]+cnt[i],INFLL);
				}else{
					int t=a[i]-cnt[i]-1;
					ans+=t;
					per(j,min(n,i+a[i]),i+2){
						++cnt[j];
					}
				}
			}else{
				cnt[i+1]=min(cnt[i+1]+cnt[i],INFLL);
			}
		}
		pt(ans,'\n');
	}
	return 0;
}