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
int n,ans,cnt[N],b[N],st[N];std::map<int,int>mmp;
signed main(){
	rd(n);
	rep(i,1,n)rd(b[i]);
	rep(i,0,63)mmp[1ll<<i]=i;
	rep(i,1,n)++cnt[mmp[b[i]&-b[i]]];
	int mx=0;
	rep(i,0,63)if(cnt[i]>cnt[mx])mx=i;
	rep(i,1,n){
		if((b[i]&-b[i])!=(1ll<<mx))st[++*st]=b[i];
	}
	pt(*st,'\n');
	rep(i,1,*st)pt(st[i],' ');
	return 0;
}