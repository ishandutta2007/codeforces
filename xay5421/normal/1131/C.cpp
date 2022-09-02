#include<cstdio>
#include<algorithm>
typedef long long ll;
#define int long long 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void read(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=(x+(x<<2)<<1)+(ch&15);if(fl)x=-x;} 
template<typename T>void print(T x){if(x<0)x=-x,putchar('-');if(x>9)print(x/10);putchar(x%10+48);}
template<typename T>void print(T x,int ch){print(x),putchar(ch);}
int n;
int a[105];
signed main(){
	read(n);rep(i,1,n)read(a[i]);
	std::sort(a+1,a+1+n);if(n==2){print(a[1],' '),print(a[2],'\n');return 0;}
	for(int i=1;i<=n;i+=2)print(a[i],' ');
	if(n&1){
		for(int i=n-1;i>=1;i-=2)print(a[i],' ');
	}else{
		for(int i=n;i>=1;i-=2)print(a[i],' ');
	}
	return 0;
}