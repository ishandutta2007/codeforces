#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
namespace FastIO{
	const int LZH=2333333;
	char lzh[LZH],*SSS=lzh,*TTT=lzh;
	inline char gc(){
		if (SSS==TTT){
			TTT=(SSS=lzh)+fread(lzh,1,LZH,stdin);
			if (SSS==TTT) return EOF; 
		}
		return *SSS++;
	}
	inline int read(){
		int x=0;
		char ch=gc();
		for (;ch<'0'||ch>'9';ch=gc());
		for (;ch>='0'&&ch<='9';ch=gc())
			x=x*10-48+ch;
		return x;
	}
	inline void write(int x){
		if (!x){
			putchar('0');
			return;
		}
		static int a[20],top;
		for (top=0;x;a[++top]=x%10,x/=10);
		for (;top;putchar(a[top--]+'0'));
	}
}
using namespace FastIO;
const int N=200005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q;
int dfn[N],ed[N],pos[N];
int st[N*2][19],dep[N],lg[N*2];
vector<pii > vec[N];
int Mn(int x,int y){
	return dep[x]<dep[y]?x:y;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	pos[x]=++*pos;
	st[*pos][0]=2*dep[x];
	dfn[x]=++*dfn;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
			st[++*pos][0]=2*dep[x];
			vec[x].PB(pii(dfn[e[i].to],ed[e[i].to]));
		}
	ed[x]=*dfn;
}
int times=0;
int LCA(int x,int y){
	++times;
	if (x>y) swap(x,y);
	int k=lg[y-x+1];
	return min(st[x][k],st[y-(1<<k)+1][k]);
}
int dis(int x,int y){
	return dep[x]+dep[y]-LCA(pos[x],pos[y]);
}
struct SEG{
	int L,a[N*3];
	void init(int n){
		for (L=1;L<=n+2;L<<=1);
	}
	void change(int x,int v){
		a[x+=L]=v;
		for (x>>=1;x;x>>=1)
			a[x]=max(a[x*2],a[x*2+1]);
	}
	int query(int x){
		return a[x+L];
	}
	int query(int l,int r){
		int ans=0;
		for (l+=L-1,r+=L+1;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=max(ans,a[l^1]);
			if (r&1) ans=max(ans,a[r^1]);
		}
		return ans;
	}
}S;
int query(int x,int rt){
	if (x==rt) return S.query(1,n);
	if ((dfn[rt]<=dfn[x]&&ed[x]<=ed[rt])||ed[x]<dfn[rt]||ed[rt]<dfn[x])
		return S.query(dfn[x],ed[x]);
	int l=0,r=vec[x].size()-1,p;
	while (l<=r){
		int mid=(l+r)/2;
		if (vec[x][mid].se>=dfn[rt])
			p=mid,r=mid-1;
		else l=mid+1;
	}
	int ans=S.query(1,vec[x][p].fi-1);
	if (vec[x][p].se!=n)
		ans=max(ans,S.query(vec[x][p].se+1,n));
	return ans;
}
struct node{
	int l,r,id;
	bool operator <(const node &a)const{
		return l<a.l;
	}
}tmp[N];
vector<node> Qvec[N];
int nxt[N],pre[N],BLK;
int id[N],Id[N],ans[N],SS,len;
int q[N*2],rk[N],tms[N];
void del(int x){
	if (!--tms[x]){
		int u=pre[x],v=nxt[u]=nxt[x];
		SS+=LCA(Id[u],Id[x])+LCA(Id[v],Id[x])-LCA(Id[u],Id[v])-2*dep[id[x]];
		pre[v]=u;
	}
}
void add(int x){
	if (!tms[x]++)
		pre[nxt[x]]=nxt[pre[x]]=x;
}
void orz(){
	int cnt=(len-1)/BLK+1;
	For(i,1,n){
		id[dfn[i]]=i;
		Id[dfn[i]]=pos[id[dfn[i]]];
		pre[i]=(i==1?n:i-1);
		nxt[i]=(i==n?1:i+1);
	}
	SS=2*n-2;
	int l=1,r=len;
	For(i,l,r) ++tms[q[i]];
	Rep(i,cnt,1){
		if (!Qvec[i].size()) continue;
		sort(Qvec[i].begin(),Qvec[i].end());
		int BR=min(len,i*BLK);
		for (;r>BR;del(q[r--]));
		int OS=SS;
		For(j,0,Qvec[i].size()-1){
			int L=Qvec[i][j].l,R=Qvec[i][j].r;
			for (;l<L;del(q[l++]));
			int OOS=SS;
			for (;r>R;del(q[r--]));
			ans[Qvec[i][j].id]-=SS;
			for (;r<BR;add(q[++r]));
			SS=OOS;
		}
		for (;l>1;add(q[--l]));
		SS=OS;
	}
}
int main(){
	n=read(); Q=read();
	For(i,1,n-1){
		int x=read(),y=read();
		add(x,y); add(y,x);
	}
	dfs(1,0);
	For(i,2,*pos) lg[i]=lg[i/2]+1;
	For(i,1,18) For(j,1,(*pos)-(1<<i)+1)
		st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	S.init(n);
	For(i,1,n) S.change(dfn[i],i);
	For(i,1,n) q[i]=rk[i]=i;
	int ed=n,rt=n,Qcnt=0;
	For(i,1,Q){
		char s=gc();
		for (;s!='u'&&s!='w'&&s!='c';s=gc());
		if (s=='u'){
			q[rk[rt=read()]=++ed]=rt;
			S.change(dfn[rt],ed);
			ans[i]=-1;
		}
		if (s=='w'){
			int x=read();
			int l=query(x,rt),r=ed;
			tmp[++Qcnt]=(node){l,r,i};
			if (l>=rk[x]) ans[i]-=2*dis(x,q[l]);
			ans[i]+=2; ans[i]=2*(n+1)-ans[i];
		}
		if (s=='c'){
			int x=read(),y=read();
			int vx=query(x,rt);
			int vy=query(y,rt);
			if (vx!=vy) ans[i]=(vx<vy?x:y)*2;
			else ans[i]=(dis(x,rt)>dis(y,rt)?x:y)*2;
		}
	}
	BLK=(Qcnt?max(1,(int)(1.3*ed/sqrt(Qcnt))):1000);
	For(i,1,Qcnt) Qvec[(tmp[i].r-1)/BLK+1].PB(tmp[i]);
	For(i,1,ed) q[i]=dfn[q[i]];
	len=ed;
	orz();
	For(i,1,Q)
		if (ans[i]!=-1)
			printf("%d\n",ans[i]/2);
}