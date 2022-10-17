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
int n,q,a[N],ans[N],r[N],fa[N],cnt[N],ins[N],st[N];
int get(int u){return u==fa[u]?u:fa[u]=get(fa[u]);}
signed main(){
	rd(n),rd(q);
	rep(i,1,n)rd(a[i]),++cnt[a[i]],r[a[i]]=i;
	rep(i,1,N-1)fa[i]=i;
	rep(i,1,n){
		int tmp=a[i],maxr=r[a[i]];
		if(ins[a[i]]){
			while(1){
				ins[st[*st]]=0;
				fa[get(st[*st])]=get(a[i]);
				if(r[st[*st]]>maxr)maxr=r[st[*st]],tmp=st[*st];
				if(st[(*st)--]==a[i])break;
			}
		}
		st[++*st]=tmp;
		ins[tmp]=1;
	}
	rep(i,1,n)ans[get(i)]=max(ans[get(i)],cnt[i]);
	int res=0;
	rep(i,1,n)if(get(i)==i)res+=ans[i];
	pt(n-res,'\n');
	return 0;
}