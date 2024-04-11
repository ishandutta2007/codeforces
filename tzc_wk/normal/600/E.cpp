#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
const int MAXP=MAXN*80;
int n,c[MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int rt[MAXN+5],ncnt=0;
struct node{int ch[2],mx;ll mxs;} s[MAXP+5];
void pushup(int k){
	if(s[k].ch[0]) s[k].mx=s[s[k].ch[0]].mx,s[k].mxs=s[s[k].ch[0]].mxs;
	else s[k].mx=s[k].mxs=0;
	if(s[k].ch[1]&&s[s[k].ch[1]].mx>s[k].mx) s[k].mx=s[s[k].ch[1]].mx,s[k].mxs=s[s[k].ch[1]].mxs;
	else if(s[k].ch[1]&&s[s[k].ch[1]].mx==s[k].mx) s[k].mxs+=s[s[k].ch[1]].mxs;
}
void add(int &k,int l,int r,int p,int x){
	if(!k) k=++ncnt;
	if(l==r){s[k].mx++;s[k].mxs=l;return;}
	int mid=(l+r)>>1;
	if(p<=mid) add(s[k].ch[0],l,mid,p,x);
	else add(s[k].ch[1],mid+1,r,p,x);
	pushup(k);
}
int merge(int x,int y,int l,int r){
	if(!x||!y) return x|y;
	int z=++ncnt,mid=(l+r)>>1;
	if(l==r){s[z].mx=s[x].mx+s[y].mx;s[z].mxs=l;return z;}
	s[z].ch[0]=merge(s[x].ch[0],s[y].ch[0],l,mid);
	s[z].ch[1]=merge(s[x].ch[1],s[y].ch[1],mid+1,r);
	pushup(z);return z;
}
ll ans[MAXN+5];
void dfs(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);rt[x]=merge(rt[x],rt[y],1,n);
	} ans[x]=s[rt[x]].mxs;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),add(rt[i],1,n,c[i],1);
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);adde(u,v);adde(v,u);}
	dfs(1,0);for(int i=1;i<=n;i++) printf("%lld%c",ans[i],(i==n)?'\n':' ');
	return 0;
}