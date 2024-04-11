#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

int a,b,c;

signed main(){
	rd(a),rd(b),rd(c);
	pt(std::min(a,b)*2+(a!=b)+c*2,'\n');
	return 0;
}