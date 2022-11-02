#include<cstdio>
#include <iostream> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set> 
using namespace std;
int n,m,f[100009],g[100009],flag;
int find(int x){
	return f[x]==x?x:(f[x]=find(f[x]));
}
void merge(int u,int v){
	int fu=find(u),fv=find(v);
	if(fu!=fv){
		f[fu]=fv;
		if(g[fu]==1) g[fv]=1;
	}
	else g[fv]=1;
}
int main(){
	memset(g,0,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		merge(u,v);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		if(f[i]==i)
			if(!g[i]) sum++; 
	printf("%d",sum);
	return 0;
}