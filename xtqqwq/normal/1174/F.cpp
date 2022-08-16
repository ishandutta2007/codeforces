#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,fsize,rt,depx;
int ms[200005],siz[200005],v[400005],nxt[400005],h[200005],dep[200005],f[200005];
bool vis[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

ll ask(int u){
	cout<<"d "<<u<<endl;
	return readint();
}

ll find(int u){
	cout<<"s "<<u<<endl;
	return readint();
}

void getroot(int u,int fa){
	ms[u]=0,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||vis[v[p]]) continue;
		getroot(v[p],u);
		siz[u]+=siz[v[p]];
		ms[u]=max(ms[u],siz[v[p]]);
	}
	ms[u]=max(ms[u],fsize-siz[u]);
	if(ms[u]<ms[rt]) rt=u;
}

void solve(int u){
	getroot(u,-1);
	ll x=ask(u);
	if(x==-1) exit(0);
	if(x==0){
		cout<<"! "<<u<<endl;
		exit(0);
	}
	if(x+dep[u]==depx){
		ll nt=find(u);
		if(nt==-1) exit(0);
		vis[u]=true;
		fsize=siz[nt],rt=0,ms[rt]=1<<30;
		getroot(nt,-1);
		solve(rt);
	}
	else{
		vis[u]=true;
		fsize=siz[f[u]],rt=0,ms[rt]=1<<30;
		getroot(f[u],-1);
		solve(rt);
	}
}

void dfs(int u,int fa){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1,f[v[p]]=u;
		dfs(v[p],u);
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dfs(1,-1);
	depx=ask(1);
	fsize=n,rt=0,ms[rt]=1<<30;
	getroot(1,-1);
	solve(rt);
	return 0;
}