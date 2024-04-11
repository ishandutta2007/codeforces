//Created time: 2022/3/6 16:03:27
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
const int MAXN=10;
const int MAXL=5.5e5;
const int ALPHA=26;
int n,len,cnt[MAXN+2][MAXL*2+5],L[MAXN+2],R[MAXN+2];
char buf[MAXL+5];
struct node{int ch[ALPHA+2],lnk,len;} s[MAXL*2+5];
int ncnt,cur;
void init(){ncnt=cur=1;}
int extend(int prv,char c){
	int id=c-'a',nw=++ncnt,p=prv;s[nw].len=s[prv].len+1;
	while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	if(!p) return s[nw].lnk=1,nw;
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1) return s[nw].lnk=q,nw;
	int cl=++ncnt;s[cl].len=s[p].len+1;
	s[cl].lnk=s[q].lnk;s[q].lnk=s[nw].lnk=cl;
	for(int i=0;i<ALPHA;i++) s[cl].ch[i]=s[q].ch[i];
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
	return nw;
}
int hd[MAXL*2+5],nxt[MAXL*2+5],to[MAXL*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
ll res=0;
void dfs(int x){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dfs(y);
		for(int i=1;i<=n+1;i++) cnt[i][x]+=cnt[i][y];
	}
	bool flg=cnt[n+1][x]>0;
	for(int i=1;i<=n;i++) flg&=(L[i]<=cnt[i][x]&&cnt[i][x]<=R[i]);
	if(flg) res+=s[x].len-s[s[x].lnk].len;
}
int main(){
	init();scanf("%s%d",buf+1,&n);len=strlen(buf+1);
	for(int i=1;i<=len;i++) cur=extend(cur,buf[i]),cnt[n+1][cur]++;
	for(int i=1;i<=n;i++){
		scanf("%s%d%d",buf+1,&L[i],&R[i]);cur=1;len=strlen(buf+1);
		for(int j=1;j<=len;j++) cur=extend(cur,buf[j]),cnt[i][cur]++;
	}
	for(int i=2;i<=ncnt;i++) adde(s[i].lnk,i);
	dfs(1);printf("%lld\n",res);
	return 0;
}