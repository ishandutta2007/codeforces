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
int n,a[N],b[N],cnt[65];
struct sth{
	int a,b,c;
	bool operator<(const sth&b)const{return a<b.a;}
}t[N],q[N];
signed main(){
	rd(n);
	rep(i,1,n)rd(t[i].a);
	rep(i,1,n)rd(t[i].b);
	rep(i,1,n)t[i].c=1;
	std::sort(t+1,t+1+n);q[1]=t[1];
	int m=1;
	rep(i,2,n){
		if(q[m].a==t[i].a)++q[m].c,q[m].b+=t[i].b;
		else q[++m]=t[i];
	}
	int res=0;
	rep(i,1,m){
		if(q[i].c>=2){res+=q[i].b;continue;}
		rep(j,1,m){
			if(q[j].c>=2&&(q[j].a&q[i].a)==q[i].a){
				res+=q[i].b;
				break;
			}
		}
	}
	pt(res,'\n');
	return 0;
}