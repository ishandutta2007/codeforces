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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
const int MAXN=3e5;
int n,qu,a[MAXN+5];multiset<int> st[MAXN+5];
int nc=1,ch[MAXN+5][26],fail[MAXN+5],ed[MAXN+5];
void insert(string s,int id){
	int cur=1;
	for(int i=0;i<s.size();i++){
		if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++nc;
		cur=ch[cur][s[i]-'a'];
	} ed[id]=cur;
}
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void getfail(){
	queue<int> q;
	for(int i=0;i<26;i++){
		if(ch[1][i]) fail[ch[1][i]]=1,q.push(ch[1][i]);
		else ch[1][i]=1;
	}
	while(!q.empty()){
		int x=q.front();q.pop();
//		printf("%d %d\n",x,fail[x]);
		for(int i=0;i<26;i++){
			if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	for(int i=1;i<=nc;i++) adde(fail[i],i);
}
int siz[MAXN+5],dep[MAXN+5],fa[MAXN+5],wson[MAXN+5];
int dfn[MAXN+5],top[MAXN+5],tim=0;
void dfs1(int x){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dep[y]=dep[x]+1;
		fa[y]=x;dfs1(y);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;dfn[x]=++tim;
	if(wson[x]) dfs2(wson[x],tp);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==wson[x]) continue;
		dfs2(y,y);
	}
}
struct node{int l,r,mx;} s[MAXN*4+5];
void pushup(int k){s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].mx=-1;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int p,int x){
	if(s[k].l==s[k].r){s[k].mx=x;return;}
	int mid=s[k].l+s[k].r>>1;
	if(p<=mid) modify(k<<1,p,x);
	else modify(k<<1|1,p,x);
	pushup(k);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mx;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return max(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
int jumpath(int x){
	int mx=-1;
	while(top[x]^1){
		chkmax(mx,query(1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	} chkmax(mx,query(1,dfn[1],dfn[x]));
	return mx;
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++){string s;cin>>s;insert(s,i);}
	build(1,1,nc);getfail();dfs1(1);dfs2(1,1);
	for(int i=1;i<=n;i++) modify(1,dfn[ed[i]],0),a[i]=0,st[ed[i]].insert(a[i]);
//	for(int i=1;i<=nc;i++) printf("%d\n",dfn[i]);
//	for(int i=1;i<=n;i++) printf("%d\n",dfn[ed[i]]);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x,v;scanf("%d%d",&x,&v);
			st[ed[x]].erase(st[ed[x]].find(a[x]));
			a[x]=v;st[ed[x]].insert(v);
			modify(1,dfn[ed[x]],*st[ed[x]].rbegin());
		} else {
			string s;int cur=1,ans=-1;cin>>s;
			for(int i=0;i<s.size();i++){
				cur=ch[cur][s[i]-'a'];
				chkmax(ans,jumpath(cur));
			} printf("%d\n",ans);
		}
	}
	return 0;
}//