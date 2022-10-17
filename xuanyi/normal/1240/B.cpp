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

const int N=300005;

int q,n,a[N],b[N],L[N],R[N],f[N];

signed main(){
	rd(q);
	while(q--){
		rd(n);
		rep(i,1,n){
			rd(a[i]);
			if(!L[a[i]])L[a[i]]=i;
			R[a[i]]=i;
			b[i]=a[i];
		}
		std::sort(b+1,b+1+n);
		int m=std::unique(b+1,b+1+n)-b-1;
		int ans=m;
		for(int i=1;i<=m;){
			int j=i+1;
			while(j<=m&&R[b[j-1]]<L[b[j]])++j;
			ans=min(ans,m-(j-i));
			i=j;
		}
		pt(ans,'\n');
		rep(i,1,n)L[a[i]]=R[a[i]]=0;
	}
	return 0;
}