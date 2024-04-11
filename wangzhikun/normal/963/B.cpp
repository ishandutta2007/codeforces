//
//  main.cpp
//  CF pre
//
//  Created by  on 2018/4/17.
//  Copyright  2018 . All rights reserved.
//

#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;

int n,fa[200020],m[200020],rt;
vector<int> G[200020];
bool dfs(int num){
	if(m[num]!=-1)return m[num];
	int sz = (int)G[num].size();
	for(int i=0;i<G[num].size();i++){
		int ct = G[num][i];
		if(dfs(ct))sz--;
	}
	m[num] = sz%2;
	return sz%2 == 1;
}

void genout(int num){
	for(int i=0;i<G[num].size();i++) if(dfs(G[num][i]))genout(G[num][i]);
	cout<<num<<endl;
	for(int i=0;i<G[num].size();i++) if(!dfs(G[num][i]))genout(G[num][i]);
}
int main() {
	memset(m,-1,sizeof(m));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>fa[i];
		if(!fa[i]){
			rt = i;
			continue;
		}
		G[fa[i]].push_back(i);
	}
	if(!dfs(rt)){
		cout<<"YES"<<endl;
		genout(rt);
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}