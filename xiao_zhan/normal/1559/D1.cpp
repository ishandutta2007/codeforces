#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m1,m2,t,fa[1050],fa2[1050];
int find(int *fa,int x){
	return (fa[x]==x)?x:fa[x]=find(fa,fa[x]);
}
vector<pair<int,int> >v;

int main(){
	for(i=1;i<=1005;i++){
		fa[i]=i;fa2[i]=i;
	}
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;i++){
		scanf("%d%d",&j,&k);
		j=find(fa,j);
		k=find(fa,k);
		fa[fa[j]]=fa[k];
	}
	for(i=1;i<=m2;i++){
		scanf("%d%d",&j,&k);
		j=find(fa2,j);
		k=find(fa2,k);
		fa2[fa2[j]]=fa2[k];
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(find(fa,j)==find(fa,i)){
				continue;
			}
			if(find(fa2,j)==find(fa2,i)){
				continue;
			}
			fa[fa[find(fa,j)]]=fa[find(fa,i)];
			fa2[fa2[find(fa2,j)]]=fa2[find(fa2,i)];
			v.push_back({i,j});
		}
	}
	printf("%d\n",v.size());
	for(auto [i,j]:v){
		printf("%d %d\n",i,j);
	}
}