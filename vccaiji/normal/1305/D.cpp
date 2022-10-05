#include<bits/stdc++.h>
using namespace std;
set<int> e[1100];
int d[1100];
int v[1100];
int dfs(int i,int fa){
	v[i]=0;
    for(auto it=e[i].begin();it!=e[i].end();it++){
    	int o=*it;
    	if(o!=fa)dfs(o,i);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].insert(v);e[v].insert(u);
		d[u]++;d[v]++;
	}
	for(int i=1;i<=n;i++) v[i]=1;
	for(;;){
		int j=0;
		for(int i=1;i<=n;i++)if(v[i]&&(d[i]>=2)){
			j=i;
			break;
		}
		if(j==0){
			int k1=0,k2=0;
			for(int k=1;k<=n;k++)if(v[k]){
			    if(k1==0) k1=k;
			    else k2=k;
		    }
		    if(k2){
		    	printf("? %d %d\n",k1,k2);
		    	fflush(stdout);
		    	int o;
		    	scanf("%d",&o);
				printf("! %d\n",o);
				fflush(stdout);
				return 0;
			}
			break;
		}
		auto it=e[j].begin();
		int k1=*it;
		it++;
		int k2=*it;
		printf("? %d %d\n",k1,k2);
		fflush(stdout);
		e[k1].erase(j);
		e[k2].erase(j);
		e[j].erase(k1);
		e[j].erase(k2);
		d[j]-=2;
		d[k1]-=1;
		d[k2]-=1;
		int o;
		scanf("%d",&o);
		if(k1!=o) dfs(k1,k1);
		if(k2!=o) dfs(k2,k2);
		if(j!=o)  dfs(j,j);
	} 
	for(int i=1;i<=n;i++)if(v[i]){
		printf("! %d\n",i);
		fflush(stdout);
		return 0;
	}
	return 0;
}