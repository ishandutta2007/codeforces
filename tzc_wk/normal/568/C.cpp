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
const int MAXN=200;
const int MAXV=400;
const int MAXM=5e5;
int l,n,m;char bel[MAXN+5],s[MAXN+5];
int hd[MAXV+5],to[MAXM+5],nxt[MAXM+5],ec=0;
void adde(int u,int v){/*printf("%d %d\n",u,v);*/to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int can[MAXV+5][MAXV+5],must[MAXV+5],_must[MAXN+5];
void dfs(int x,int st){
	if(can[st][x]) return;can[st][x]=1;
	for(int e=hd[x];e;e=nxt[e]) dfs(to[e],st);
}
int get(int x){return (bel[s[x]-'a'+1]=='C');}
vector<pii> could[MAXV+5];
bool check(){
//	printf("checking:\n");
//	for(int i=1;i<=n;i++) printf("%d%c",_must[i]," \n"[i==n]);
	queue<pii> q;
	for(int i=1;i<=n;i++) if(~_must[i]) q.push(mp(i,_must[i]));
	while(!q.empty()){
		pii p=q.front();q.pop();
		int x=p.fi,y=p.se,nd=x+y*n;_must[x]=y;
		for(pii pp:could[nd]){
			int nx=pp.fi,ny=pp.se;
			if(~_must[nx]&&_must[nx]!=ny) return 0;
			if(!~_must[nx]) q.push(pp);
		}
	} return 1;
}
char res[MAXN+5];
void prt(int bg){
	for(int i=bg;i<=n;i++) for(int j='a';j<'a'+l;j++){
		if(!~_must[i]||(bel[j-'a'+1]=='C')==_must[i]){
			res[i]=j;int nd=i+(bel[j-'a'+1]=='C')*n;
			for(pii p:could[nd]) _must[p.fi]=p.se;
			break;
		}
	} printf("%s\n",res+1);
}
void work(int x,char c){
	bool ok=0;
	for(int j=1;j<x;j++) _must[j]=get(j);
	for(int j=x;j<=n;j++) _must[j]=must[j];
	for(int j=s[x]+1;j<'a'+l;j++) ok|=(bel[j-'a'+1]==c);
	if(ok&&(!~_must[x]||_must[x]==(c=='C'))){
		_must[x]=(c=='C');
		if(check()){
			for(int i=1;i<x;i++) res[i]=s[i];
			for(int j=s[x]+1;j<'a'+l;j++) if(bel[j-'a'+1]==c){res[x]=j;break;}
			prt(x+1);exit(0);
		}
	}
}
int main(){
	scanf("%s%d%d",bel+1,&n,&m);l=strlen(bel+1);
	for(int i=1;i<=m;i++){
		int x,y;char bx,by;scanf("%d %c %d %c",&x,&bx,&y,&by);
		adde(x+n*(bx=='C'),y+n*(by=='C'));
		adde(y+n*(1-(by=='C')),x+n*(1-(bx=='C')));
	} for(int i=1;i<=n<<1;i++) dfs(i,i);
	scanf("%s",s+1);memset(must,-1,sizeof(must));
	for(int i=1;i<=n;i++){
		if(can[i+n][i]&&can[i][i+n]) return puts("-1"),0;
		if(can[i+n][i]) must[i]=0;if(can[i][i+n]) must[i]=1;
	} int msk=0;
	for(int i=1;i<=l;i++) msk|=(bel[i]=='V'),msk|=(bel[i]=='C')<<1;--msk;
	if(msk^2){
		for(int i=1;i<=n;i++){
			if(~must[i]&&must[i]!=msk) return puts("-1"),0;
			must[i]=msk;
		}
	}
//	for(int i=1;i<=n;i++) printf("%d%c",must[i]," \n"[i==n]);
	for(int i=1;i<=n<<1;i++) for(int j=1;j<=n<<1;j++) if(can[i][j]){
		if(j<=n) could[i].pb(mp(j,0));else could[i].pb(mp(j-n,1));
	}
	for(int i=n;~i;i--){
		bool flg=1;
		for(int j=1;j<=i;j++) if(~must[j]&&must[j]!=get(j)) flg=0;
		if(!flg) continue;
		if(i==n){
			for(int j=1;j<=i;j++) _must[j]=get(j);
			for(int j=i+1;j<=n;j++) _must[j]=must[j];
			if(check()){
				for(int j=1;j<=n;j++) putchar(s[j]);putchar('\n');
				return 0;
			} else continue;
		} if(s[i+1]!='a'+l-1){
			if(bel[s[i+1]-'a'+1]=='V') work(i+1,'V'),work(i+1,'C');
			else work(i+1,'C'),work(i+1,'V');
		}
	} puts("-1");
	return 0;
}
/*
CCCCCCCC
3 1
1 C 3 V
aaa

VVCC
6 6
1 V 2 V
1 V 3 C
3 C 2 C
4 V 5 V
4 V 6 C
6 C 5 C
aaaaaa
*/