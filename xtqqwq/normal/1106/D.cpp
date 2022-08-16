#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,x,y,tot=0;
int v[200005],nxt[200005],h[100005];
bool vis[100005];
priority_queue<int,vector<int>,greater<int> > q;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	q.push(1); vis[1]=true;
	while(!q.empty()){
		int u=q.top(); q.pop();
		printf("%d ",u);
		for(int p=h[u];p;p=nxt[p]){
			if(vis[v[p]]) continue;
			vis[v[p]]=true;
			q.push(v[p]);
		}
	}
	printf("\n");
	return 0;
}