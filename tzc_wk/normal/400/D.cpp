#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[505],fa[100005],dis[505][505],ans[505][505];
map<int,int> id;
int par(int x){
	return x==fa[x]?x:fa[x]=par(fa[x]) ;
}
bool check(){
	int index=1;
	for(int i=1;i<=k;i++){
		int x=par(index++);
		for(int j=2;j<=c[i];++j){
			if(x!=par(index++))    return false;
		}
	}
	return true;
}
void floyd(){
    for(int K=1;K<=k;K++)
    	for(int I=1;I<=k;I++)
    		for(int J=1;J<=k;J++){
    			dis[I][J]=min(dis[I][J],dis[I][K]+dis[K][J]);
			}
}
int main(){
	cin>>n>>m>>k;
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++)   fa[i]=i;
	for(int i=1;i<=k;i++)	dis[i][i]=0;
	for(int i=1;i<=k;i++)   scanf("%d",&c[i]);
	int index=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=c[i];j++){
			id[index++]=i;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(!w){
			int a=par(u),b=par(v);
			fa[a]=b;
			dis[id[u]][id[v]]=0;
			dis[id[v]][id[u]]=0;
		}
		else{
			dis[id[u]][id[v]]=min(dis[id[u]][id[v]],w);
			dis[id[v]][id[u]]=min(dis[id[v]][id[u]],w);
		}
	}
	if(!check())	return puts("No"),0;
	puts("Yes");
	floyd();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(dis[i][j]==0x3f3f3f3f)  
				cout<<"-1 ";
			else
				printf("%d ",dis[i][j]);
		}
		puts("");
	}
	return 0;
}
/*
4 4 2
1 3
2 3 0
3 4 0
2 4 1
2 1 2
*/