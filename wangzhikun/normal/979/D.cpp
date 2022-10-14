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

const int MAX = 1e5 + 5;

struct t_n{
	int mi;
	t_n *bit[2];
	t_n(){
		mi = MAX;
		bit[0] = bit[1] = nullptr;
	}
}*rt[MAX];

vector<int> di[MAX];
int q,t,u,k,x,s;
bool chk[MAX];

void init(){
	for(int i=1;i<MAX;i++){
		for(int j=i;j<MAX;j+=i)
			di[j].push_back(i);
		rt[i] = new t_n();
	}
}

void add(int k,int u){
	t_n *cur = rt[k];
	cur->mi = min(cur->mi,u);
	for(int i=18;i>=0;i--){
		if(cur->bit[u >> i & 1] == nullptr)
			cur->bit[u >> i & 1] = new t_n();
		cur = cur->bit[u >> i & 1];
		cur->mi = min(cur->mi, u);
	}
}

int que(int x, int k,int s){
	t_n *cur = rt[k];
	if(x%k != 0 || cur->mi + x > s)
		return -1;
	int ret = 0;
	for(int i=18;i>=0;i--){
		int ct = x >> i & 1;
		if(cur->bit[ct^1] != nullptr && cur->bit[ct^1]->mi + x <=s){
			ret += (ct^1)<<i;
			cur = cur->bit[ct^1];
		}else{
			ret += ct<<i;
			cur = cur->bit[ct];
		}
	}
	return ret;
}

int main(){
	init();
	cin>>q;
	while(q--){
		scanf("%d", &t);
		if (t == 1){
			cin>>u;
			if(!chk[u]){
				chk[u] = true;
				for(int k : di[u])
					add(k,u);
			}
		}else{
			cin>>x>>k>>s;
			cout<<que(x,k,s)<<endl;
		}
	}
}