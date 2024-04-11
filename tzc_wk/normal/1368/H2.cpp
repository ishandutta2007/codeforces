//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,m,qu;
struct mat{
	int a[2][2];
	mat(){memset(a,63,sizeof(a));}
	mat operator *(const mat &rhs){
		mat res;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
			chkmin(res.a[i][j],a[i][k]+rhs.a[k][j]);
		return res;
	}
};
struct solver{
	int n,m;char s1[MAXN+5],s2[MAXN+5];
	mat get(int x,int y){
		mat res;
		res.a[0][0]=x+y;res.a[0][1]=m+2-x-y;
		res.a[1][0]=m+x+y;res.a[1][1]=2-x-y;
		return res;
	}
	struct node{int l,r,s1,s2,tg1,tg2;mat v[2][2];} s[MAXN*4+5];
	void pushup(int k){
		for(int a=0;a<2;a++) for(int b=0;b<2;b++)
			s[k].v[a][b]=s[k<<1].v[a][b]*s[k<<1|1].v[a][b];
		s[k].s1=s[k<<1].s1+s[k<<1|1].s1;
		s[k].s2=s[k<<1].s2+s[k<<1|1].s2;
	}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			for(int a=0;a<2;a++) for(int b=0;b<2;b++)
				s[k].v[a][b]=get((s1[l]=='B')^a,(s2[l]=='B')^b);
			s[k].s1=(s1[l]=='B');s[k].s2=(s2[l]=='B');
			return;
		} int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void tag1(int k){
		swap(s[k].v[0][0],s[k].v[1][0]);
		swap(s[k].v[0][1],s[k].v[1][1]);
		s[k].s1=s[k].r-s[k].l+1-s[k].s1;
		s[k].tg1^=1;
	}
	void tag2(int k){
		swap(s[k].v[0][0],s[k].v[0][1]);
		swap(s[k].v[1][0],s[k].v[1][1]);
		s[k].s2=s[k].r-s[k].l+1-s[k].s2;
		s[k].tg2^=1;
	}
	void pushdown(int k){
		if(s[k].tg1){tag1(k<<1);tag1(k<<1|1);s[k].tg1=0;}
		if(s[k].tg2){tag2(k<<1);tag2(k<<1|1);s[k].tg2=0;}
	}
	void modify(int k,int l,int r,int t){
		if(l<=s[k].l&&s[k].r<=r) return ((t==1)?tag1(k):tag2(k)),void();
		int mid=(pushdown(k),s[k].l+s[k].r>>1);
		if(r<=mid) modify(k<<1,l,r,t);
		else if(l>mid) modify(k<<1|1,l,r,t);
		else modify(k<<1,l,mid,t),modify(k<<1|1,mid+1,r,t);
		pushup(k);
	}
	void init(){build(1,1,n);}
	mat query(){return s[1].v[0][0];}
	int ask1(){return s[1].s1;}
	int ask2(){return s[1].s2;}
} H,V;
int calc(){
	mat m1=H.query(),m2=V.query();
	return min(min(
	min(m1.a[0][0]+V.ask1()+V.ask2(),m1.a[0][1]+V.ask1()+m-V.ask2()),
	min(m1.a[1][0]+m-V.ask1()+V.ask2(),m1.a[1][1]+m-V.ask1()+m-V.ask2())),min(
	min(m2.a[0][0]+H.ask1()+H.ask2(),m2.a[0][1]+H.ask1()+n-H.ask2()),
	min(m2.a[1][0]+n-H.ask1()+H.ask2(),m2.a[1][1]+n-H.ask1()+n-H.ask2())));
}
int main(){
	scanf("%d%d%d",&n,&m,&qu);V.m=H.n=n;V.n=H.m=m;
	scanf("%s%s%s%s",H.s1+1,H.s2+1,V.s1+1,V.s2+1);
	H.init();V.init();printf("%d\n",calc());
	while(qu--){
		char c;int l,r;cin>>c>>l>>r;
		switch(c){
			case 'L':{H.modify(1,l,r,1);break;}
			case 'R':{H.modify(1,l,r,2);break;}
			case 'U':{V.modify(1,l,r,1);break;}
			case 'D':{V.modify(1,l,r,2);break;}
		} printf("%d\n",calc());
	}
	return 0;
}