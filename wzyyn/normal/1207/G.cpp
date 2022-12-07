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
#define y1 hfjskghsdjkfg
using namespace std;
const int N=400005;
vector<pii> vece[N];
vector<pii> vecQ[N];
int nd=1,ch[N][26],posi[N];
int fail[N],dfn[N],ed[N];
int ans[N],t[N],n,Q,q[N];
vector<int> e[N];
char s[N];
int insert(char *s,int len){
	int x=1;
	For(i,1,len){
		int c=s[i]-'a';
		if (!ch[x][c])
			ch[x][c]=++nd;
		x=ch[x][c];
	}
	return x;
}
void dfs(int x){
	dfn[x]=++*dfn;
	For(i,0,e[x].size()-1)
		dfs(e[x][i]);
	ed[x]=*dfn;
}
void build_ACM(){
	int h=0,t=0;
	For(i,0,25)
		if (!ch[1][i])
			ch[1][i]=1;
		else{
			q[++t]=ch[1][i];
			fail[ch[1][i]]=1;
		}
	while (h!=t){
		int x=q[++h];
		e[fail[x]].PB(x);
		For(i,0,25)
			if (!ch[x][i])
				ch[x][i]=ch[fail[x]][i];
			else{
				fail[ch[x][i]]=ch[fail[x]][i];
				q[++t]=ch[x][i];
			}
	}
	dfs(1);
}
void change(int x,int v){
	for (;x<N;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&(-x)) ans+=t[x];
	return ans;
}
void solve_prb(int x,int nd){
	change(dfn[nd],1);
	For(i,0,vecQ[x].size()-1){
		int id=vecQ[x][i].fi;
		ans[id]=ask(ed[posi[id]])-ask(dfn[posi[id]]-1);
	}
	For(i,0,vece[x].size()-1){
		int nx=ch[nd][vece[x][i].se];
		solve_prb(vece[x][i].fi,nx);
	}
	change(dfn[nd],-1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int tp,fa=0;
		char s[5];
		scanf("%d",&tp);
		if (tp!=1) scanf("%d",&fa);
		scanf("%s",s+1);
		vece[fa].PB(pii(i,s[1]-'a'));
	}
	scanf("%d",&Q);
	For(i,1,Q){
		int id;
		scanf("%d%s",&id,s+1);
		vecQ[id].PB(pii(i,i));
		int len=strlen(s+1);
		posi[i]=insert(s,len);
	}
	build_ACM();
	solve_prb(0,1);
	For(i,1,Q) printf("%d\n",ans[i]);
}