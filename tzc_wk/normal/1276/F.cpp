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
#define mt make_tuple
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
const int MAXP=2e5;
const int MAX_ND=MAXP<<5;
const int LOG_N=19;
char str[MAXN+5];int n;
struct graph{
	int hd[MAXP+5],to[MAXP+5],nxt[MAXP+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
};
struct SAM{
	struct node{int ch[27],len,lnk;} s[MAXP+5];
	int cur,ncnt,ed[MAXN+5];graph t;
	SAM(){cur=ncnt=1;}
	void extend(char c,int ps){
		int id=c-'a',nw=++ncnt,p=cur;
		s[nw].len=s[cur].len+1;ed[ps]=nw;cur=nw;
		while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
		if(!p) return s[nw].lnk=1,void();
		int q=s[p].ch[id];
		if(s[q].len==s[p].len+1) return s[nw].lnk=q,void();
		int cl=++ncnt;s[cl].len=s[p].len+1;
		s[cl].lnk=s[q].lnk;s[q].lnk=cl;s[nw].lnk=cl;
		for(int i=0;i<26;i++) s[cl].ch[i]=s[q].ch[i];
		while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
	}
	void build(){for(int i=2;i<=ncnt;i++) t.adde(s[i].lnk,i);}
	ll calc(){
		ll res=0;
		for(int i=1;i<=ncnt;i++) res+=s[i].len-s[s[i].lnk].len;
		return res;
	}
} s_tot,fw,bk;//forward backward
#define g1 fw.t
#define g2 bk.t
int dep[MAXP+5];pii st[MAXP*2+5][LOG_N+2];
int dfn[MAXP+5],rid[MAXP+5],tim=0,eul[MAXP+5],tim_eul=0;
void dfs0(int x,int f){
	rid[dfn[x]=++tim]=x;
	st[eul[x]=++tim_eul][0]=mp(dep[x],x);
	for(int e=g2.hd[x];e;e=g2.nxt[e]){
		int y=g2.to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs0(y,x);
		st[eul[x]=++tim_eul][0]=mp(dep[x],x);
	}
}
int getlca(int x,int y){
	x=eul[x];y=eul[y];if(x>y) swap(x,y);
	int k=31-__builtin_clz(y-x+1);
	return min(st[x][k],st[y-(1<<k)+1][k]).se;
}
int getdis(int x,int y){
	int lc=getlca(x,y);
	return bk.s[x].len+bk.s[y].len-(bk.s[lc].len<<1);
}
struct data{
	int lc,lft,rit;ll sum;
	data(int _lc=0,int _lft=0,int _rit=0,ll _sum=0):
		lc(_lc),lft(_lft),rit(_rit),sum(_sum){}
	data operator +(const data &rhs){
		if(!lc) return rhs;
		if(!rhs.lc) return data(lc,lft,rit,sum);
		return data(getlca(lc,rhs.lc),lft,rhs.rit,
		sum+rhs.sum+getdis(rid[rit],rid[rhs.lft]));
	}
};
namespace segtree{
	struct node{int ch[2];data d;} s[MAX_ND+5];
	int ncnt=0;
	void pushup(int k){s[k].d=s[s[k].ch[0]].d+s[s[k].ch[1]].d;}
	void insert(int &k,int l,int r,int x){
		if(!k) k=++ncnt;if(l==r) return s[k].d=data(rid[x],x,x,0),void();
		int mid=l+r>>1;
		(x<=mid)?insert(s[k].ch[0],l,mid,x):insert(s[k].ch[1],mid+1,r,x);
		pushup(k);
	}
	int merge(int x,int y,int l,int r){
		if(!x||!y) return x+y;int z=++ncnt;
		if(l==r) return s[z].d=data(rid[l],l,l,0),z;
		int mid=l+r>>1;
		s[z].ch[0]=merge(s[x].ch[0],s[y].ch[0],l,mid);
		s[z].ch[1]=merge(s[x].ch[1],s[y].ch[1],mid+1,r);
		return pushup(z),z;
	}
}
using segtree::insert;
using segtree::merge;
int rt[MAXP+5];ll res=0;
void dfs(int x,int f){
	for(int e=g1.hd[x];e;e=g1.nxt[e]){
		int y=g1.to[e];if(y==f) continue;
		dfs(y,x);rt[x]=merge(rt[x],rt[y],1,bk.ncnt);
	} data d=segtree::s[rt[x]].d;
	if(d.lc) res+=1ll*(fw.s[x].len-fw.s[fw.s[x].lnk].len)*
	(d.sum+getdis(rid[d.lft],rid[d.rit])+(getdis(d.lc,1)<<1));
}
int main(){
	scanf("%s",str+1);n=strlen(str+1);
	for(int i=1;i<=n;i++) s_tot.extend(str[i],/*19260817*/i);
	for(int i=1;i<n;i++) fw.extend(str[i],i);
	for(int i=n;i>1;i--) bk.extend(str[i],i);
	fw.build();bk.build();
	dfs0(1,0);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=tim_eul;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	for(int i=1;i<n-1;i++) insert(rt[fw.ed[i]],1,bk.ncnt,dfn[bk.ed[i+2]]);
	dfs(1,0);res>>=1;res+=2+s_tot.calc()+fw.calc()+bk.calc();
	printf("%lld\n",res);
	return 0;
}