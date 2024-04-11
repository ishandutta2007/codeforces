#include<bits/stdc++.h>
using namespace std;
struct edge{
	int nex,to;
}ed[200005],ed1[200005];
int h[200005],cnt,h1[200005],cnt1,rd[200005],cd[200005],mi[200005],demi[200005];
bool ans[200005];
void add(int x,int y){
	cnt++;
	ed[cnt].to=y;
	ed[cnt].nex=h[x];
	h[x]=cnt;
}
void add1(int x,int y){
	cnt1++;
	ed1[cnt1].to=y;
	ed1[cnt1].nex=h1[x];
	h1[x]=cnt1;
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); 
		add1(y,x);
		rd[y]++;
		cd[x]++;
	}
	queue<int>q;
	memset(mi,127,sizeof mi);
	memset(demi,127,sizeof demi);
	for(int i=1;i<=n;i++){
		if(!rd[i])q.push(i);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=ed[i].nex){
			int v=ed[i].to;
			mi[v]=min(mi[v],min(u,mi[u]));
			rd[v]--;
			if(!rd[v])q.push(v);
		}
	}
	for(int i=1;i<=n;i++)if(rd[i]){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!cd[i])q.push(i);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=h1[u];i;i=ed1[i].nex){
			int v=ed1[i].to;
			demi[v]=min(demi[v],min(u,demi[u]));
			cd[v]--;
			if(!cd[v])q.push(v);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(i<mi[i]&&i<demi[i])ans[i]=1,res++;
	}
	printf("%d\n",res);
	for(int i=1;i<=n;i++){
		printf("%c","EA"[ans[i]]);
	}
	return 0;
}