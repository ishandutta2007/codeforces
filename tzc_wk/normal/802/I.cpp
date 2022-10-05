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
const int MAXN=2e5;
struct node{int ch[27],lnk,len,ed;} s[MAXN+5];
int lst=1,ncnt=1;char str[MAXN+5];
void extend(char c){
	int nw=++ncnt,id=c-'a';s[nw].len=s[lst].len+1;s[nw].ed=1;
	int p=lst;while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	lst=nw;if(!p) return s[nw].lnk=1,void();
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1){s[nw].lnk=q;return;}
	int cl=++ncnt;s[cl].lnk=s[q].lnk;s[q].lnk=cl;
	for(int i=0;i<26;i++) s[cl].ch[i]=s[q].ch[i];
	s[nw].lnk=cl;s[cl].len=s[p].len+1;
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
}
void clear(){
	for(int i=1;i<=ncnt;i++){
		memset(s[i].ch,0,sizeof(s[i].ch));
		s[i].len=s[i].lnk=s[i].ed=0;
	} lst=ncnt=1;
}
void build(char *s){
	clear();int len=strlen(s+1);
	for(int i=1;i<=len;i++) extend(s[i]);
}
int ord[MAXN*2+5],siz[MAXN*2+5];
bool cmp(int x,int y){return s[x].len>s[y].len;}
void solve(){
	scanf("%s",str+1);build(str);ll res=0;
	for(int i=1;i<=ncnt;i++) ord[i]=i;
	sort(ord+1,ord+ncnt+1,cmp);
	for(int i=1;i<=ncnt;i++) siz[i]=s[i].ed;
//	for(int i=1;i<=ncnt;i++) printf("%d %d\n",i,s[i].lnk);
	for(int i=1;i<=ncnt;i++){
		int x=ord[i];
		if(s[x].lnk) siz[s[x].lnk]+=siz[x];
	} //for(int i=1;i<=ncnt;i++) printf("%d %d\n",siz[i],s[i].len);
	for(int i=1;i<=ncnt;i++) res+=1ll*siz[i]*siz[i]*(s[i].len-s[s[i].lnk].len);
	printf("%lld\n",res);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}