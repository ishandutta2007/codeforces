#include<cstdio>
#include<algorithm>
typedef long long ll;
#define int long long 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void read(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=(x+(x<<2)<<1)+(ch&15);if(fl)x=-x;} 
template<typename T>void print(T x){if(x<0)x=-x,putchar('-');if(x>9)print(x/10);putchar(x%10+48);}
template<typename T>void print(T x,int ch){print(x),putchar(ch);}
int n,ans=1,a[10005],b[10005],na,nb;
signed main(){
	read(n);
	rep(i,1,n){
		read(a[i]),read(b[i]);
		if(na<nb){
			if(a[i]<nb)na=a[i];
			else ans+=na!=nb,na=nb,ans+=std::min(a[i],b[i])-nb;
		}else{
			if(b[i]<na)nb=b[i];
			else ans+=na!=nb,nb=na,ans+=std::min(a[i],b[i])-na;
		}
		na=a[i],nb=b[i];
	}
	print(ans,'\n');
	return 0;
}