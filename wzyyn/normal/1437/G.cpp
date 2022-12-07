#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=300005;
int n,Q;
int ans[N],tp[N];
const int M=15000005;
struct Tree{
	int ls[M],rs[M],tg[M],nd,la=0;
	Tree(){
		memset(tg,-1,sizeof(tg));
	}
	void change(int &nk,int k,int l,int r,int x,int y,int v){
		if (k<=nd){
			nk=++nd; tg[nk]=tg[k];
			ls[nk]=ls[k]; rs[nk]=rs[k];
		}
		else
			nk=k;
		if (x<=l&&r<=y)
		 	return tg[nk]=max(tg[nk],v),void(0);
		int mid=(l+r)/2;
		if (x<=mid) change(ls[nk],ls[k],l,mid,x,y,v);
		if (y>mid) change(rs[nk],rs[k],mid+1,r,x,y,v);
	}
	int ask(int k,int l,int r,int p){
		if (!k) return -1;
		if (l==r) return tg[k];
		int mid=(l+r)/2;
		if (p<=mid) return max(ask(ls[k],l,mid,p),tg[k]);
		return max(ask(rs[k],mid+1,r,p),tg[k]);
	}
}TR;
struct AC_automaton{
	int ch[N][26],pos[N];
	int q[N],fa[N],nd=1;
	vector<pii> op[N];
	vector<int> opp[N];
	vector<int> e[N];
	vector<int> vQ[N];
	char s[N];
	void build(){
		For(i,1,n){
			scanf("%s",s+1);
			int x=1;
			for (int j=1;s[j];j++){
				if (!ch[x][s[j]-'a'])
					ch[x][s[j]-'a']=++nd;
				x=ch[x][s[j]-'a'];
			}
			opp[x].PB(i);
			op[i].PB(pii(0,0));
		}
		int h=0,t=0;
		For(i,0,25)
			if (!ch[1][i])
				ch[1][i]=1;
			else{
				fa[ch[1][i]]=1;
				q[++t]=ch[1][i];
			}
		while (h!=t){
			int x=q[++h];
			For(i,0,25)
				if (!ch[x][i])
					ch[x][i]=ch[fa[x]][i];
				else{
					fa[ch[x][i]]=ch[fa[x]][i];
					q[++t]=ch[x][i];
				}
		}
		For(i,2,nd)
			e[fa[i]].PB(i);
	}
	void insertC(int x,int y,int i){
		op[x].PB(pii(y,i));
	}
	int sum=0;
	void insertQ(int id){
		scanf("%s",s+1);
		int l=strlen(s+1);
		assert((sum+=l)<=300000);
		int x=1;
		for (int i=1;i<=l;++i){
			x=ch[x][s[i]-'a'];
			vQ[x].PB(id);
		}
	}
	void dfs(int x,int rt){
		TR.la=TR.nd;
		for (auto p:opp[x])
			for (int i=0;i<op[p].size();i++){
				int l=op[p][i].se;
				int r=(i==op[p].size()-1?Q:op[p][i+1].se-1);
				TR.change(rt,rt,0,Q,l,r,op[p][i].fi);
			}
		int tmp=TR.nd;
		for (auto i:vQ[x])
			ans[i]=max(ans[i],TR.ask(rt,0,Q,i));
		for (auto i:e[x]){
			dfs(i,rt);
			TR.nd=tmp;
		}
	}
	void solve(){
		dfs(1,0);
	}
}AC;

int main(){
	scanf("%d%d",&n,&Q);
	AC.build();
	For(i,1,Q){
		ans[i]=-1;
		scanf("%d",&tp[i]);
		if (tp[i]==1){
			int x,y;
			scanf("%d%d",&x,&y);
			AC.insertC(x,y,i);
		}
		else
			AC.insertQ(i);
	}
	AC.solve();
	For(i,1,Q)
		if (tp[i]==2)
			printf("%d\n",ans[i]);
}