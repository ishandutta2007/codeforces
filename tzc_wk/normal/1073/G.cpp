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
const int MAXP=4e5;
const int LOG_N=19;
int n,qu;char str[MAXN+5];
struct node{int ch[26],lnk,len,ed;} s[MAXP+5];
int cur=1,ncnt=1,ed[MAXN+5];
void extend(char c,int ps){
	int nw=++ncnt,id=c-'a',p=cur;
	s[nw].len=s[cur].len+1;s[nw].ed=1;ed[ps]=nw;cur=nw;
	while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	if(!p) return s[nw].lnk=1,void();
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1) return s[nw].lnk=q,void();
	int cl=++ncnt;s[cl].len=s[p].len+1;
	s[cl].lnk=s[q].lnk;s[q].lnk=cl;s[nw].lnk=cl;
	for(int i=0;i<26;i++) s[cl].ch[i]=s[q].ch[i];
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
}
int hd[MAXP+5],to[MAXP+5],nxt[MAXP+5],ec=0;
void adde(int u,int v){/*printf("%d %d\n",u,v);*/to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
pii st[MAXP*2+5][LOG_N+2];
int dfn[MAXP+5],tim=0,dep[MAXP+5],bgt[MAXP+5];
void dfs0(int x){
	st[dfn[x]=++tim][0]=mp(dep[x],x);
	bgt[x]=tim;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dep[y]=dep[x]+1;dfs0(y);
		st[dfn[x]=++tim][0]=mp(dep[x],x);
	}
}
int getlca(int x,int y){
	x=dfn[x],y=dfn[y];if(x>y) swap(x,y);
	int k=31-__builtin_clz(y-x+1);
	return min(st[x][k],st[y-(1<<k)+1][k]).se;
}
vector<int> g[MAXP+5];
void _adde(int u,int v){/*printf("adde %d %d\n",u,v);*/g[u].pb(v);}
int stk[MAXP+5],tp=0,siz[MAXP+5];
void insert(int x){
//	printf("insert %d\n",x);
	if(!tp) return stk[++tp]=x,void();
	int lc=getlca(x,stk[tp]);
//	printf("%d\n",lc);
	while(tp>1&&dep[stk[tp-1]]>dep[lc]) _adde(stk[tp-1],stk[tp]),--tp;
	if(tp&&dep[stk[tp]]>dep[lc]) _adde(lc,stk[tp--]);
	if(!tp||stk[tp]!=lc) stk[++tp]=lc;
	stk[++tp]=x;
}
void fin(){
	while(tp>=2) _adde(stk[tp-1],stk[tp]),tp--;
	stk[tp--]=0;
}
bool in[MAXP+5];ll res=0;
void dfs(int x){
	for(int y:g[x]){
		dfs(y);res+=1ll*s[x].len*siz[x]*siz[y];
		siz[x]+=siz[y];
	}
}
void clr(int x){
	siz[x]=0;
	for(int y:g[x]) clr(y);
	g[x].clear();
}
ll calc(vector<int> vec){
	sort(vec.begin(),vec.end(),[&](int x,int y){return bgt[x]<bgt[y];});
	res=0;for(int x:vec) res+=1ll*siz[x]*s[x].len,siz[x]++,in[x]=1;
	if(!in[1]) insert(1);
	for(int i=0;i<vec.size();i++) if(i==0||vec[i]!=vec[i-1]) insert(vec[i]);fin();
	dfs(1);clr(1);return res;
}
void solve(){
	int l1,l2;scanf("%d%d",&l1,&l2);vector<int> A,B,C;
	while(l1--){int x;scanf("%d",&x);x=n-x+1;A.pb(ed[x]);C.pb(ed[x]);}
	while(l2--){int x;scanf("%d",&x);x=n-x+1;B.pb(ed[x]);C.pb(ed[x]);}
	printf("%lld\n",calc(C)-calc(A)-calc(B));
}
int main(){
	scanf("%d%d%s",&n,&qu,str+1);
	reverse(str+1,str+n+1);
	for(int i=1;i<=n;i++) extend(str[i],i);
	for(int i=2;i<=ncnt;i++) adde(s[i].lnk,i);
//	for(int i=1;i<=ncnt;i++) printf("%d\n",s[i].len);
	dfs0(1);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=ncnt*2;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	while(qu--) solve();
	return 0;
}