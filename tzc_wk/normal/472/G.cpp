#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc((x%10)+'0');}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
using namespace fastio;
typedef unsigned long long u64;
const int MAXN=2e5;
int n,m,qu;char s[MAXN+5],t[MAXN+5];
u64 f1[64][3130],f2[64][3130];
void tog(u64 a[64][3130],int pos){
	register int mn=min(63,pos);
	for(register int i=0;i<=mn;i++) a[i][pos-i>>6]|=(1ull<<(pos-i&63));
}
int main(){
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	for(int i=1;i<=n;i++) if(s[i]^48) tog(f1,i-1);
	for(int i=1;i<=m;i++) if(t[i]^48) tog(f2,i-1);
	read(qu);
	for(int e=0;e<qu;e++){
		int x,y,l;read(x);read(y);read(l);
		u64 *pt1=f1[x&63]+(x>>6),*pt2=f2[y&63]+(y>>6);
		register int i=0,ans0=0,ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0,ans7=0;
		int stp=l>>6;
		for(i=0;i+8<stp;i+=8,pt1+=8,pt2+=8){
			#define popc __builtin_popcountll
			#define calc(x) ans##x+=popc(pt1[x]^pt2[x])
			calc(0);calc(1);calc(2);calc(3);
			calc(4);calc(5);calc(6);calc(7);
		}
		for(;i<stp;i++,pt1++,pt2++) ans0+=popc(pt1[0]^pt2[0]);
		ans0+=popc((pt1[0]^pt2[0])&((1ull<<(l&63))-1));
		print(ans0+ans1+ans2+ans3+ans4+ans5+ans6+ans7);putc('\n');
	} print_final();
	return 0;
}