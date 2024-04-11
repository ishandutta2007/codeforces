//by xay5421 2449670833@qq.com
#include<cmath>
#include<set>
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
int n,ans[N],s[N],t[N];std::set<int>id;
void upd(int i,int x){
	for(;i<=n;i+=i&-i)t[i]+=x;
}
int qry(int i){
	int res=0;
	for(;i;i&=i-1)res+=t[i];
	return res;
}
signed main(){
	rd(n);
	rep(i,1,n)rd(s[i]),upd(i,i);
	rep(i,1,n)id.insert(i);
	for(int i=n;i>=1;--i){
		int l=1,r=n,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(qry(mid-1)>=s[i])res=mid,r=mid-1;
			else l=mid+1;
		}
		int pos=*id.lower_bound(res);
		upd(pos,-pos);
		id.erase(pos);
		ans[i]=pos;
	}
	rep(i,1,n)pt(ans[i],i==n?'\n':' ');
	return 0;
}