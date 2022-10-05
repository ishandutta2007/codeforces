#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
typedef unsigned int u32;
typedef unsigned long long u64;
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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const int MOD=998244353;
int n,qu;char str[MAXN+5];
struct matrix{
	ll a[2][2];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator *(const matrix &rhs){
		matrix ret;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
			ret.a[i][j]+=a[i][k]*rhs.a[k][j];
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) ret.a[i][j]%=MOD;
		return ret;
	}
};
struct node{int l,r;matrix v;} s[MAXN*4+5];
matrix get(int x){
	matrix ret;ret.a[0][1]=1;
	ret.a[1][1]=(str[x]^48)+1;
	ret.a[1][0]=(str[x-1]!='1')?0:(9-(str[x]^48));
	return ret;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].v=get(l);return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	s[k].v=s[k<<1|1].v*s[k<<1].v;
}
void modify(int k,int x){
	if(s[k].l==s[k].r){s[k].v=get(x);return;}
	int mid=s[k].l+s[k].r>>1;
	if(x<=mid) modify(k<<1,x);
	else modify(k<<1|1,x);
	s[k].v=s[k<<1|1].v*s[k<<1].v;
}
int main(){
	scanf("%d%d%s",&n,&qu,str+1);build(1,1,n);
	while(qu--){
		int x;char d;cin>>x>>d;str[x]=d;
		modify(1,x);if(x!=n) modify(1,x+1);
		printf("%d\n",s[1].v.a[1][1]);
	}
	return 0;
}
/*
5 1
31216
2 3
*/