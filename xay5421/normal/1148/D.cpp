#include<cstdio>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>void pt(T x,int ch){pt(x),putchar(ch);}

const int N=300005;

int n,len,a[N],b[N],cnta,cntb;

struct ff{
	int l,r,id;
	bool operator<(const ff&b)const{return l<b.l;}
}c[N];

signed main(){
	rd(n);
	rep(i,1,n){
		rd(a[i]),rd(b[i]);
		if(a[i]<b[i])++cnta;
		else ++cntb; 
	}
	if(cnta<cntb){
		rep(i,1,n)a[i]=n*2-a[i]+1,b[i]=n*2-b[i]+1;
	}
	int mx=0,pos=0;
	rep(i,1,n){
		if(a[i]<b[i]){
			c[++len]=(ff){a[i],b[i],i};
			if(b[i]>mx)mx=b[i],pos=len;
		}
	}
	pt(len,'\n');
	pt(c[pos].id,' ');
	--len;
	rep(i,pos,len)c[i]=c[i+1];
	std::sort(c+1,c+len+1);
	for(int i=len;i>=1;--i)pt(c[i].id,' ');
	return 0;
}