#include<bits/stdc++.h>

using namespace std;

const int N=500005;
int n,m;
struct node{
	int y,id,dir;
};
vector<node> e[2][N];
int q[N],ban[N],ans[N];

void dfs(int x,int c){
	for (int i=0;i<=1;i++){
		for (;e[c][x].size();){
			node tmp=e[c][x].back();
			e[c][x].pop_back();
			if (ban[tmp.id]) continue;
			ban[tmp.id]=1;
			if (tmp.id<=m)
				ans[tmp.id]=(tmp.dir?1:2);
			dfs(tmp.y,c);
		}
		c^=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[v-1][x].push_back((node){y,i,0});
		e[v-1][y].push_back((node){x,i,1});
	}
	int re=0;
	for (int i=1;i<=n;i++)
		if (e[0][i].size()&1){
			++re;
			if ((~e[1][i].size())&1)
				q[++*q]=i;
		}
	for (int i=1;i<=n;i++)
		if ((~e[0][i].size())&1)
			if (e[1][i].size()&1)
				q[++*q]=i;
	int id=m;
	for (int i=1;i<=*q;i+=2){
		e[0][q[i]].push_back((node){q[i+1],++id,0});
		e[0][q[i+1]].push_back((node){q[i],id,1});
	}
	for (int i=1;i<=n;i++)
		dfs(i,0);
	printf("%d\n",re);
	for (int i=1;i<=m;i++)
		printf("%d",ans[i]);
}