//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=200005;
int T,n,a[N],b[N],ans[N];char s[N];
bool push(int*a,int x){
	if(*a>0&&x<a[*a])return 1;
	a[++*a]=x;return 0;
}
signed main(){
	rd(T);
	while(T--){
		rd(n);
		scanf("%s",s+1);
		bool ok;
		rep(i,0,9){
			*a=0,*b=0;ok=1;
			int r=0,l=n;
			rep(j,1,n){
				int x=s[j]&15;
				if(x<i){
					if(push(a,x)){ok=0;break;}
					r=j;
				}
				else if(x>i){
					if(push(b,x)){ok=0;break;}
					l=min(l,j);
				}
			}
			if(ok){
				rep(j,1,n){
					int x=s[j]&15;
					if(x<i)ans[j]=1;
					else if(x>i)ans[j]=2;
					else{
						if(j>r)ans[j]=1;
						else if(j<l)ans[j]=2;
						else{ok=0;goto tag;}
					}
				}
				break;
			}
		}
		tag:;
		if(!ok)puts("-");
		else{
			rep(i,1,n)pt(ans[i]);puts("");
		}
	}
	return 0;
}