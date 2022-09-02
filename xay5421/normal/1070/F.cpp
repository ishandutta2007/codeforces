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
const int N=400005;
int n,k;char s[5];std::vector<int>g[4];
bool cmp(const int&x,const int&y){return x>y;} 
signed main(){
	rd(n);
	rep(i,1,n){
		scanf("%s",s);int x;rd(x);
		g[(s[0]&1)<<1|(s[1]&1)].push_back(x);
	}
	rep(i,0,3){
		std::sort(g[i].begin(),g[i].end(),cmp);
		rep(j,1,(int)g[i].size()-1)g[i][j]+=g[i][j-1];
	}
	int ans=0;
	for(int i=0;i<=(int)g[0].size()&&i<=(int)g[3].size();++i){
		int hav=(int)g[3].size()-i,b,c;
		if((int)g[2].size()<(int)g[1].size()){
			b=(int)g[2].size(),c=min((int)g[1].size(),b+hav);
		}else{
			c=(int)g[1].size(),b=min((int)g[2].size(),c+hav);
		}
//		debug("%lld\n",(g[3].empty()?0:g[3].back()));
//		debug("%lld\n",(b?g[2][b-1]:0));
//		debug("%lld\n",(c?g[1][c-1]:0));
//		debug("%lld\n",(i?g[0][i-1]:0));
		ans=max(ans,(g[3].empty()?0:g[3].back())+(b?g[2][b-1]:0)+(c?g[1][c-1]:0)+(i?g[0][i-1]:0));
	}
	pt(ans,'\n');
	return 0;
}