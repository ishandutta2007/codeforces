#include<bits/stdc++.h>
using namespace std;
int n;
bool in[1<<22]={};
bool vis[1<<23]={};
void dfs(int i){
	vis[i]=true;
	if(i<(1<<n)){
		if(!vis[(1<<(n+1))-1-i]) dfs((1<<(n+1))-1-i);
	}
	else{
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				if(!vis[i^(1<<j)]) dfs(i^(1<<j));
			}
		}
		if((!vis[i^(1<<n)])&&in[i^(1<<n)]) dfs(i^(1<<n));
	}
}
int main(){
	int m,num=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		in[a]=true;
	}
	for(int i=0;i<(1<<n);i++){
		if((!vis[i])&&in[i]){
			num++;
			dfs(i);
		}
	}
	printf("%d",num);
	return 0;
}