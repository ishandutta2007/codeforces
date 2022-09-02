#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

const int N=200005;
int n,m,ta,tb,k,ans,a[N],b[N];

signed main(){
	rd(n),rd(m),rd(ta),rd(tb),rd(k);
	if(k>=n||k>=m){
		puts("-1");
		return 0;
	}
	rep(i,1,n)rd(a[i]),a[i]+=ta;
	rep(i,1,m)rd(b[i]);
	for(int i=0;i<n&&i<=k;++i){
		int pos=std::lower_bound(b+1,b+1+m,a[i+1])-b;
		pos+=k-i;
		if(pos>m){
			puts("-1");
			return 0;
		}
		ans=std::max(ans,b[pos]+tb);
	}
	pt(ans,'\n');
	return 0;
}