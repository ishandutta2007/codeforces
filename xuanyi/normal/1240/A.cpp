//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
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

int q,n,A[N],cnt[N];

bool cmp(const int&x,const int&y){return x>y;}

signed main(){
	rd(q);
	while(q--){
		rd(n);
		rep(i,1,n)rd(A[i]);
		int x,a,y,b,K;
		rd(x),rd(a),rd(y),rd(b);
		rd(K);
		if(x<y)std::swap(x,y),std::swap(a,b); 
		std::sort(A+1,A+1+n,cmp);
		rep(i,1,n)A[i]+=A[i-1];
		int c1=0,c2=0,c3=0;bool flag=0;
		rep(i,1,n){
			if(i%a==0&&i%b==0){
				++c3;
			}else if(i%a==0){
				++c1;
			}else if(i%b==0){
				++c2;
			}
			if(A[c3]/100*(x+y)+(A[c3+c1]-A[c3])/100*x+(A[c3+c1+c2]-A[c3+c1])/100*y>=K){
				flag=1;
				pt(i,'\n');
				break;
			}
		}
		if(!flag)puts("-1");
	}
	return 0;
}