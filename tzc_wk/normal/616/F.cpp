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
const int MAXP=1e6;
const int MAXN=1e5;
struct node{int ch[26],len,ed,lnk;} s[MAXP+5];
int n,cur=1,ncnt=1;ll val[MAXP+5];string str[MAXN+5];
int hd[MAXP+5],to[MAXP+5],nxt[MAXP+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void extend(char c,int v){
	int id=c-'a',nw=++ncnt,p=cur;
	s[nw].len=s[cur].len+1;val[nw]=v;cur=nw;
	while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	if(!p) return s[nw].lnk=1,void();
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1) return s[nw].lnk=q,void();
	int cl=++ncnt;s[cl].len=s[p].len+1;
	s[cl].lnk=s[q].lnk;s[q].lnk=cl;s[nw].lnk=cl;
	for(int i=0;i<26;i++) s[cl].ch[i]=s[q].ch[i];
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
}
void dfs(int x){
	for(int e=hd[x];e;e=nxt[e]) dfs(to[e]),val[x]+=val[to[e]];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>str[i];
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);cur=1;
		for(int j=0;j<str[i].size();j++)
			extend(str[i][j],x);
	}
	for(int i=2;i<=ncnt;i++) adde(s[i].lnk,i);
	dfs(1);ll res=0;
	for(int i=1;i<=ncnt;i++) if(s[i].len^s[s[i].lnk].len)
		chkmax(res,1ll*s[i].len*val[i]);
	printf("%lld\n",res);
	return 0;
}