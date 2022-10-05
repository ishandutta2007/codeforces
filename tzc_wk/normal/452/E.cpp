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
const int MAXN=3e5;
const int MAXP=MAXN<<1;
const int MOD=1e9+7;
void add(int &x,int v){((x+=v)>=MOD)&&(x-=MOD);}
int l1,l2,l3,d[MAXN+5];
char s1[MAXN+5],s2[MAXN+5],s3[MAXN+5];
struct node{int ch[27],lnk,len,ed[3];} s[MAXP+5];
int cur=1,ncnt=1;
void extend(char c,int x){
	int nw=++ncnt,id=c-'a',p=cur;
	s[nw].len=s[cur].len+1;s[nw].ed[x]=1;cur=nw;
	while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	if(!p) return s[nw].lnk=1,void();
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1) return s[nw].lnk=q,void();
	int cl=++ncnt;s[cl].len=s[p].len+1;
	s[cl].lnk=s[q].lnk;s[q].lnk=cl;s[nw].lnk=cl;
	for(int i=0;i<26;i++) s[cl].ch[i]=s[q].ch[i];
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
}
int hd[MAXP+5],to[MAXP+5],nxt[MAXP+5],ec=0,siz[MAXP+5][3];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void dfs(int x){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dfs(y);
		for(int i=0;i<3;i++) siz[x][i]+=siz[y][i];
	}
}
int main(){
	scanf("%s%s%s",s1+1,s2+1,s3+1);
	int l1=strlen(s1+1),l2=strlen(s2+1),l3=strlen(s3+1);
	cur=1;for(int i=1;i<=l1;i++) extend(s1[i],0);
	cur=1;for(int i=1;i<=l2;i++) extend(s2[i],1);
	cur=1;for(int i=1;i<=l3;i++) extend(s3[i],2);
	for(int i=1;i<=ncnt;i++) for(int j=0;j<3;j++) siz[i][j]=s[i].ed[j];
	for(int i=2;i<=ncnt;i++) adde(s[i].lnk,i);dfs(1);
	for(int i=1;i<=ncnt;i++){
		int cnt=1ll*siz[i][0]*siz[i][1]*siz[i][2]%MOD;
		add(d[s[s[i].lnk].len+1],cnt);add(d[s[i].len+1],(MOD-cnt)%MOD);
	} int sum=0;
	for(int i=1;i<=min(l1,min(l2,l3));i++){
		add(sum,d[i]);printf("%d ",sum);
	}
	return 0;
}