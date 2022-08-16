#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
int v[300005],nxt[300005],h[150005],du[150005],f[150005],t[150005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[y]++;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot; du[x]++;
}

int getf(int v){if(f[v]==v)return v;return f[v]=getf(f[v]);}

void dfs(int u,int fa){
	printf("%d ",u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
	}
}

int main(){
	n=readint();
	int x,y;
	for(int i=1;i<=n;i++) t[i]=f[i]=i;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		int fx=getf(x),fy=getf(y);
		f[fy]=fx;
		addedge(fy,t[fx]);
		t[fx]=t[fy];
	}
	for(int i=1;i<=n;i++){
		if(du[i]==1){
			dfs(i,-1);
			return 0;
		}
	}
	return 0;
}