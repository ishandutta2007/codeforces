#include<bits/stdc++.h>
using namespace std;
vector<int> e[210000];
int n;
int sz[210000];
void dfs1(int i,int fa){
	sz[i]=1;
	for(int j : e[i]){
		if(j!=fa){
			dfs1(j,i);
			sz[i]^=sz[j];
		}
	}
}
void dfs2(int i,int fa){
	for(int j :e[i]){
		if(j!=fa)if(!sz[j])dfs2(j,i);
	}
	printf("%d\n",i);
	for(int j : e[i]){
		if(j!=fa)if(sz[j])dfs2(j,i);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int p;
		scanf("%d",&p);
		if(p){
			e[i].push_back(p);
			e[p].push_back(i);
		}
	}
	if(n%2==0){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	dfs1(1,1);
	dfs2(1,1);
	return 0;
}