#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
#define int long long 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void read(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=(x+(x<<2)<<1)+(ch&15);if(fl)x=-x;} 
template<typename T>void print(T x){if(x<0)x=-x,putchar('-');if(x>9)print(x/10);putchar(x%10+48);}
template<typename T>void print(T x,int ch){print(x),putchar(ch);}
int n,pre[150005],nxt[150005],fa1[150005],fa2[150005];
int get1(int x){return fa1[x]==x?x:fa1[x]=get1(fa1[x]);}
int get2(int x){return fa2[x]==x?x:fa2[x]=get2(fa2[x]);}
signed main(){
	read(n);rep(i,1,n)fa1[i]=fa2[i]=i;
	rep(i,2,n){
		int u,v;read(u),read(v);
		int lu=get1(u),lv=get1(v),ru=get2(u),rv=get2(v);
		nxt[ru]=lv,pre[lv]=ru;
		fa1[lv]=lu,fa2[ru]=rv;
	}
	int pos=-1;
	rep(i,1,n)if(!pre[i]){
		pos=i;break;
	}
	while(pos){
		print(pos,' ');
		pos=nxt[pos]; 
	}
	return 0;
}