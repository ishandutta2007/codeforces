//
//  main.cpp
//  Round 482
//
//  Created by  on 2018/5/15.
//  Copyright  2018 . All rights reserved.
//

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<int> G[300010];
ll n,x,y,u,v,fa[300010],size[300010];

void dfs(int num,int f){
	fa[num] = f;
	size[num] = 1;
	for(int i=0;i<G[num].size();i++){
		int ct = G[num][i];
		if(ct == f)continue;
		dfs(ct,num);
		size[num]+=size[ct];
	}
}
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(x,-1);
	int tsz = size[y];
	while(fa[y]!=x){
		y = fa[y];
	}
	cout<<n*(n-1)-(size[x]-size[y])*tsz<<endl;
	return 0;
}