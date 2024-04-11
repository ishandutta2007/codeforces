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
const int MAXN=2e5;
const int MAXK=10;
int n,qu,m;char str[MAXN+5];
struct node{int l,r,cnt[MAXK+2][MAXK+2],fst,lst,lz;} s[MAXN*4+5];
void pushup(int k){
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) s[k].cnt[i][j]=s[k<<1].cnt[i][j]+s[k<<1|1].cnt[i][j];
	s[k].cnt[s[k<<1].lst][s[k<<1|1].fst]++;s[k].lst=s[k<<1|1].lst;s[k].fst=s[k<<1].fst;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].lz=-1;if(l==r){s[k].fst=s[k].lst=str[l]-'a';return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void pushdown(int k){
	if(~s[k].lz){
		s[k<<1].lz=s[k<<1].fst=s[k<<1].lst=s[k].lz;
		memset(s[k<<1].cnt,0,sizeof(s[k<<1].cnt));
		s[k<<1].cnt[s[k].lz][s[k].lz]=s[k<<1].r-s[k<<1].l;
		s[k<<1|1].lz=s[k<<1|1].fst=s[k<<1|1].lst=s[k].lz;
		memset(s[k<<1|1].cnt,0,sizeof(s[k<<1|1].cnt));
		s[k<<1|1].cnt[s[k].lz][s[k].lz]=s[k<<1|1].r-s[k<<1|1].l;
		s[k].lz=-1;
	}
}
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].lz=s[k].fst=s[k].lst=x;
		memset(s[k].cnt,0,sizeof(s[k].cnt));
		s[k].cnt[x][x]=s[k].r-s[k].l;return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
int main(){
	scanf("%d%d%d%s",&n,&qu,&m,str+1);build(1,1,n);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){int l,r;char c;cin>>l>>r>>c;modify(1,l,r,c-'a');}
		else{
			char ss[MAXK+2];int rk[MAXK+2]={0},ans=1;
			scanf("%s",ss+1);for(int i=1;i<=m;i++) rk[ss[i]-'a']=i;
			for(int i=0;i<m;i++) for(int j=0;j<m;j++) if(rk[i]>=rk[j])
				ans+=s[1].cnt[i][j];
			printf("%d\n",ans);
		}
	}
	return 0;
}