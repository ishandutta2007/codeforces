//Created time: 2022/3/6 13:13:30
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
template<typename T1,typename T2> void chkmin(T1 &x, T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x, T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getc();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getc();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getc();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void readstr(char *s){
		char c=getc();
		while(c<=32||c>=127) c=getc();
		while(c>32&&c<127) s[0]=c,s++,c=getc();
		(*s)=0;
	}
	void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
	void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
using namespace fastio;
#endif
const int MAXN=2e5;
const int ALPHA=26;
const int MAXP=MAXN<<6;
int n,qu;char str[MAXN+5];
struct node{int ch[ALPHA+2],lnk,len;} s[MAXN+5];
int ncnt,ed[MAXN+5];
void init(){ncnt=ed[0]=1;}
int extend(int prv,char c){
	int id=c-'a',nw=++ncnt,p=prv;s[nw].len=s[prv].len+1;
	while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	if(!p) return s[nw].lnk=1,nw;
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1) return s[nw].lnk=q,nw;
	int cl=++ncnt;s[cl].len=s[p].len+1;
	s[cl].lnk=s[q].lnk;s[nw].lnk=s[q].lnk=cl;
	for(int i=0;i<ALPHA;i++) s[cl].ch[i]=s[q].ch[i];
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
	return nw;
}
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXN+5],edt[MAXN+5],tim=0;
void dfs0(int x){
	dfn[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]){int y=to[e];dfs0(y);}
	edt[x]=tim;
}
namespace hjtree{
	struct node{int ch[2],val;} s[MAXP+5];
	int rt[MAXN+5],ncnt=0;
	int modify(int k,int l,int r,int p){
		int z=++ncnt,mid=l+r>>1;s[z]=s[k];s[z].val++;if(l==r) return z;
		if(p<=mid) s[z].ch[0]=modify(s[k].ch[0],l,mid,p);
		else s[z].ch[1]=modify(s[k].ch[1],mid+1,r,p);
		return z;
	}
	int query(int k,int l,int r,int ql,int qr){
		if(!k||(ql<=l&&r<=qr)) return s[k].val;int mid=l+r>>1;
		if(qr<=mid) return query(s[k].ch[0],l,mid,ql,qr);
		else if(ql>mid) return query(s[k].ch[1],mid+1,r,ql,qr);
		else return query(s[k].ch[0],l,mid,ql,mid)+query(s[k].ch[1],mid+1,r,mid+1,qr);
	}
}
using hjtree::modify;
using hjtree::rt;
using hjtree::query;
int main(){
	scanf("%s%d",str+1,&qu);n=strlen(str+1);init();
	for(int i=1;i<=n;i++) ed[i]=extend(ed[i-1],str[i]);
	for(int i=2;i<=ncnt;i++) adde(s[i].lnk,i);
	dfs0(1);
	for(int i=1;i<=n;i++) rt[i]=modify(rt[i-1],1,tim,dfn[ed[i]]);
	while(qu--){
		int l,r,len;static char buf[MAXN+5];static int pos[MAXN+5];
		scanf("%d%d%s",&l,&r,buf+1);len=strlen(buf+1);pos[0]=1;
		for(int i=1;i<=len;i++) pos[i]=(!pos[i-1])?0:s[pos[i-1]].ch[buf[i]-'a'];
		bool flg=0;
		for(int i=len;~i;i--) if(pos[i]){
			for(int j=(i==len)?0:(buf[i+1]-'a'+1);j<ALPHA;j++){
				int cur=s[pos[i]].ch[j];
				if(cur){
					int L=l+i,R=r;
					if(L<=R&&query(rt[R],1,tim,dfn[cur],edt[cur])-query(rt[L-1],1,tim,dfn[cur],edt[cur])){
						for(int k=1;k<=i;k++) putchar(buf[k]);putchar(j+'a');putchar('\n');
						flg=1;break;
					}
				}
			}
			if(flg) break;
		}
		if(!flg) puts("-1");
	}
	return 0;
}