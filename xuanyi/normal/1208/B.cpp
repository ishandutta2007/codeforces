//by xay5421 2449670833@qq.com
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
const int N=2005;
int n,a[N],b[N],tot[N],ans;
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]),b[i]=a[i];
	std::sort(b+1,b+1+n);
	rep(i,1,n)a[i]=std::lower_bound(b+1,b+1+n,a[i])-b;
	for(int i=n;i>=1;--i){
		if(tot[a[i]]){
			ans=max(ans,n-i);
			break;
		}
		++tot[a[i]];
	}
	if(ans==0){return puts("0"),0;}
	memset(tot,0,sizeof(tot));
	rep(i,1,n){
		if(++tot[a[i]]>1)break;
		for(int j=n;j>=i;--j){
			if(!tot[a[j]]){
				++tot[a[j]];
			}else{
				rep(k,j+1,n)--tot[a[k]];
				ans=max(ans,n-j+i);
				break;
			}
		}
	}
	pt(n-ans,'\n');
	return 0;
}