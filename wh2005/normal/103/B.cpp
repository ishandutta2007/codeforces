#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[109];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	if(n!=m){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		int fu=find(u),fv=find(v);
		if(fu!=fv){f[fu]=fv;}
	}
	for(int i=1;i<n;i++){
		if(find(i)!=find(i+1)){
			printf("NO\n");
			return 0;
		}
	}
	printf("FHTAGN!\n");
	return 0;
}