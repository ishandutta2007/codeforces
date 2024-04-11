//by xay5421 2449670833@qq.com
#include<cstdio>
#include<vector> 
#include<algorithm>
#define int long long
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;typedef unsigned long long ull;
template<typename T>inline void rd(T&x){int f=0,c;while(c=getchar(),c<48||57<c)f^=!(c^45);x=(c&15);while(c=getchar(),47<c&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=400005;
int n,k,len,a[N],b[N],l[N],r[N];
int fpow(int a,int b){
	int res=1;
	for(int i=1;i<=b;++i){
		res*=a;
		if(res>len)return len;
	}
	return res;
}
signed main(){
	rd(n),rd(k);k=k*8/n;
	rep(i,1,n)rd(a[i]);
	std::sort(a+1,a+1+n);
	rep(i,1,n)b[i]=a[i];
	len=std::unique(b+1,b+1+n)-b-1;
	k=fpow(2,k);
	rep(i,1,n){
		a[i]=std::lower_bound(b+1,b+1+len,a[i])-b;
		if(!l[a[i]])l[a[i]]=i;
		r[a[i]]=i;
	}
	int ans=n;
	for(int i=1;i+k-1<=len;++i){
		ans=min(ans,n-(r[i+k-1]-l[i]+1));
	}
	pt(ans,'\n');
	return 0;
}