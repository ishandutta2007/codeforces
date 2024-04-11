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
const int MAXN=3e4;
const int INF=0xc0c0c0c0c0c0c0c0ll;
int n,qu,a[MAXN+5],b[MAXN+5];
int ord1[MAXN+5],ord2[MAXN+5],ban[MAXN+5],pos1[MAXN+5],pos2[MAXN+5];
struct matrix{
	ll a[3][3];
	matrix(){memset(a,192,sizeof(a));}
	matrix operator *(const matrix &rhs){
		matrix ret;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++)
			chkmax(ret.a[i][j],a[i][k]+rhs.a[k][j]);
		return ret;
	}
};
matrix get(int x){
	matrix ret;ret.a[0][1]=0;ret.a[1][2]=0;
	ret.a[2][0]=(x>2)?((ban[x]!=x-1&&ban[x-1]!=x-2&&ban[x-2]!=x)?1ll*a[x]*b[x-1]+1ll*a[x-1]*b[x-2]+1ll*a[x-2]*b[x]:INF):INF;
	chkmax(ret.a[2][0],(x>2)?((ban[x]!=x-2&&ban[x-1]!=x&&ban[x-2]!=x-1)?1ll*a[x]*b[x-2]+1ll*a[x-1]*b[x]+1ll*a[x-2]*b[x-1]:INF):INF);
	ret.a[2][1]=(x>1)?((ban[x]!=x-1&&ban[x-1]!=x)?1ll*a[x]*b[x-1]+1ll*a[x-1]*b[x]:INF):INF;
	ret.a[2][2]=(ban[x]!=x)?1ll*a[x]*b[x]:INF;
	return ret;
}
struct node{int l,r;matrix v;} s[MAXN*4+5];
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
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ord1[i]=i;
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),ord2[i]=i;
	sort(ord1+1,ord1+n+1,[](int x,int y){return a[x]<a[y];});
	sort(ord2+1,ord2+n+1,[](int x,int y){return b[x]<b[y];});
	for(int i=1;i<=n;i++) pos1[ord1[i]]=i,pos2[ord2[i]]=i;
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) ban[pos1[i]]=pos2[i];
//	for(int i=1;i<=n;i++) printf("%d\n",ban[i]);
	build(1,1,n);
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);x=pos1[x];y=pos1[y];swap(ban[x],ban[y]);
		modify(1,x);if(x+1<=n) modify(1,x+1);if(x+2<=n) modify(1,x+2);
		modify(1,y);if(y+1<=n) modify(1,y+1);if(y+2<=n) modify(1,y+2);
		printf("%lld\n",max(max(s[1].v.a[2][0],s[1].v.a[2][1]),s[1].v.a[2][2]));
	}
	return 0;
}
/*
4 15
70 46 78 69
90 93 83 11
2 3
3 4
4 1
3 1
4 3
3 1
2 4
3 1
3 2
3 4
2 3
1 2
1 4
4 1
1 2
*/