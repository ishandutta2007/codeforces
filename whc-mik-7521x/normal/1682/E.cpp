#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,p[N],a[N],b[N];
struct node{
	int to,val,num;
	bool operator<(const node b)const{
		return val<b.val;
	}
};
vector<node>ed[N];
bool vis[N];
void dfs(int u){
	if(vis[u])return;
	vis[u]=1;
	for(auto it:ed[u])dfs(it.to),printf("%d ",it.num);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),a[i]=i;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			int j=i,cnt=0;
			while(!b[j])b[j]=++cnt,j=p[j];
		}
    }
	stable_sort(a+1,a+n+1,[&](int x,int y){return b[x]<b[y];});
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(b[x]>b[y])swap(x,y);
		ed[x].push_back((node){y,b[y],i});
	}
	for(int i=1;i<=n;i++)stable_sort(ed[i].begin(),ed[i].end());
	for(int i=1;i<=n;i++)if(!vis[a[i]])dfs(a[i]);
	return 0;
}