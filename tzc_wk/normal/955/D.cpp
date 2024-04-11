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
const int MAXN=5e5;
const int MAXP=1.5e6;
int n,m,k;char s1[MAXN+5],s2[MAXN+5];
struct node{int ch[26];int lnk,len;} s[MAXP+5];
int cur=1,ncnt=1,ed[MAXP+5];
void extend(char c,int ps){
	int id=c-'a';
	if(s[cur].ch[id]) return cur=ed[ps]=s[cur].ch[id],void();
	int nw=++ncnt,p=cur;
	s[nw].len=s[cur].len+1;cur=nw;ed[ps]=nw;
	while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	if(!p) return s[nw].lnk=1,void();
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1) return s[nw].lnk=q,void();
	int cl=++ncnt;s[cl].len=s[p].len+1;
	s[cl].lnk=s[q].lnk;s[q].lnk=s[nw].lnk=cl;
	for(int i=0;i<26;i++) s[cl].ch[i]=s[q].ch[i];
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
}
int hd[MAXP+5],to[MAXP+5],nxt[MAXP+5],ec=0,mn[MAXP+5];
void adde(int u,int v){/*printf("%d %d\n",u,v);*/to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void clear(){
	memset(hd,0,sizeof(hd));ec=0;
	memset(mn,63,sizeof(mn));
	memset(ed,0,sizeof(ed));
	for(int i=1;i<=ncnt;i++){
		memset(s[i].ch,0,sizeof(s[i].ch));
		s[i].lnk=s[i].len=0;
	} cur=ncnt=1;
}
void dfs(int x){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dfs(y);
		chkmin(mn[x],mn[y]);
	}
}
void work(int *val){
	clear();
	for(int i=1;i<=n;i++) extend(s1[i],i);cur=1;
	for(int i=1;i<=m;i++) extend(s2[i],i+n);
	for(int i=k;i<=n;i++) mn[ed[i]]=i;
	for(int i=2;i<=ncnt;i++) adde(s[i].lnk,i);
	dfs(1);for(int i=1;i<=m;i++) val[i]=mn[ed[i+n]];
//	for(int i=1;i<=m;i++) printf("%d%c",val[i]," \n"[i==m]);
}
int v1[MAXN+5],v2[MAXN+5];
int main(){
	scanf("%d%d%d%s%s",&n,&m,&k,s1+1,s2+1);
	work(v1);reverse(s1+1,s1+n+1);reverse(s2+1,s2+m+1);work(v2);
//	printf("%s\n%s\n",s1+1,s2+1);
	for(int i=1;i<m;i++){
		int p1=v1[i],p2=n-v2[m-i]+1;
		if(i>k||m-i>k) continue;
//		printf("%d %d\n",p1,p2);
		if(p1<p2) return printf("Yes\n%d %d\n",p1-k+1,p2),0;
	}
	if(m<=k){
		clear();reverse(s1+1,s1+n+1);reverse(s2+1,s2+m+1);
		for(int i=1;i<=m;i++) extend(s2[i],i);
		for(int i=1,cur=1,len=0;i<=n;i++){
			while(cur&&!s[cur].ch[s1[i]-'a']) cur=s[cur].lnk,len=s[cur].len;
			if(!cur) cur=1,len=0;
			else if(s[cur].ch[s1[i]-'a']){
				cur=s[cur].ch[s1[i]-'a'];len++;
			} //printf("%d %d\n",i,len);
			if(len==m){
				int l=max(i-k+1,1),r=l+k-1;
				if(r+k<=n) return printf("Yes\n%d %d\n",l,r+1),0;
				r=min(i+k-1,n);l=r-k+1;
				if(l>k) return printf("Yes\n%d %d\n",1,l),0;
			}
		}
	}
	puts("No");
	return 0;
}