#include<bits/stdc++.h>

using namespace std;

const int N=800050;
int n;
pair<int,int> a[N];

int v[N*2],tg[N*2],sz[N*2];
int ch[N*2][2],fa[N*2],rt,nd;
long long ans;
void addv(int k,int val){
	v[k]+=val;
	tg[k]+=val;
}
void pushdown(int k){
	if (!tg[k]) return;
	if (ch[k][0]) addv(ch[k][0],tg[k]);
	if (ch[k][1]) addv(ch[k][1],tg[k]);
	tg[k]=0;
}
void pushup(int x){
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
void rotate(int x){
	int y=fa[x],z=fa[y];
	int l=(ch[y][1]==x),r=(l^1);
	if (z) ch[z][ch[z][1]==y]=x;
	fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r]; ch[x][r]=y;
	pushup(y);
	pushup(x);
}
void Down(int x){
	if (fa[x]) Down(fa[x]);
	pushdown(x);
}
void splay(int x){
	Down(x);
	for (;fa[x];rotate(x)){
		int y=fa[x],z=fa[y];
		if (z) rotate((ch[y][1]==x)^(ch[z][1]==y)?x:y);
	}
	rt=x;
}
int findrk(int x,int rk){
	if (rk==sz[ch[x][0]]+1)
		return x;
	if (rk<=sz[ch[x][0]])
		return findrk(ch[x][0],rk);
	return findrk(ch[x][1],rk-sz[ch[x][0]]-1);
}
void insert(int &k,int val,int vf){
	if (!k){
		k=++nd; v[k]=val; fa[k]=vf;
		return;
	}
	pushdown(k);
	if (v[k]<=val) insert(ch[k][1],val,k);
	else insert(ch[k][0],val,k);
}
void dfs(int k,int &val,int &las){
	if (!k) return;
	pushdown(k);
	dfs(ch[k][0],val,las);
	if (val>=0) ans-=1ll*(v[k]-las)*val;
	las=v[k]; --val;
	dfs(ch[k][1],val,las);
}
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i].second);
		scanf("%d",&a[i].first);
		a[i].first+=a[i].second;
	}
	sort(a+1,a+n+1);
	nd=2; rt=1;
	ch[1][0]=2; fa[2]=1;
	sz[2]=1; sz[1]=2;
	for (int i=1;i<=n;i++){
		int p=findrk(rt,i);
		splay(p);
		addv(ch[p][1],a[i].first-a[i-1].first);
		//cout<<233<<' '<<p<<' '<<v[p]<<endl;
		insert(rt,a[i].second,0);
		splay(nd);
		++nd; v[nd]=a[i].second;
		fa[ch[nd-1][1]]=nd; fa[nd]=nd-1;
		ch[nd][1]=ch[nd-1][1]; ch[nd-1][1]=nd;
		pushup(nd); pushup(nd-1);
		ans+=a[i].second;
	}
	int val=n+1,las=0;
	dfs(rt,val,las);
	printf("%lld\n",ans);
}