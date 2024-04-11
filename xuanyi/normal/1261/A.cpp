//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
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

const int N=2005;

int T,n,m,top,ans[N][2];char t[N],s[N];

void push(int l,int r){
	ans[++top][0]=l;
	ans[top][1]=r; 
	while(l<r){
		std::swap(s[l],s[r]);
		++l,--r;
	}
}

signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		scanf("%s",s+1);
		for(int i=1;i<m;++i)t[i*2-1]='(',t[i*2]=')';
		for(int i=m*2-1;i<=n;++i)t[i]='(';
		top=0;
		for(int i=1;i<=n;++i){
			if(s[i]==t[i])continue;
			int j;
			for(j=i;j<=n;++j)if(s[j]==t[i])break;
			if(j>n)continue;
			push(i,j);
		}
		pt(top,'\n');
		rep(i,1,top)pt(ans[i][0],' '),pt(ans[i][1],'\n');
	}
	return 0;
}