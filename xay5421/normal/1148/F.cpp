#include<cstdio>
#define pp(x) __builtin_popcountll(x)
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

const int N=300005;
int n,val[N],mask[N],cnt[N],sum;

signed main(){
	rd(n);rep(i,1,n)rd(val[i]),rd(mask[i]),sum+=val[i],cnt[i]=pp(mask[i]);
	if(sum>0){rep(i,1,n)val[i]=-val[i];sum=-sum;}
	int s=0;
	rep(i,0,61){
		int now=0;
		rep(j,1,n){
			if(mask[j]>>i&1){
				if(!--cnt[j]){
					if(pp(mask[j]&((1ll<<i)|s))&1){
						now-=val[j];
					}else now+=val[j];
				}
			}
		}
		if(now>0)s|=1ll<<i;
	}
	pt(s,'\n');
	return 0;
}