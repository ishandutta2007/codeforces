//
//  main.cpp
//  Avito Code Challenge 2018
//
//  Created by  on 2018/5/27.
//  Copyright  2018 . All rights reserved.
//

#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;


ll mod = 998244353;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;y=0;return a;
	}
	ll d = exgcd(b, a%b, y, x);
	y-=a/b*x;
	return d;
}
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b, a%b);
}
ll inv(ll a){
	ll x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
ll pow(ll a,ll b){
	ll c = 1,d = 1;
	for(int i=0;i<60;i++){
		if(c&b)d = (d*a)%mod;
		a = (a*a)%mod;
		c*=2;
	}
	return d;
}


vector<int> G[100010];

int size[100010] = {0};

void dfs1(int num,int f){
	size[num] = num;
	for(int i=0;i<G[num].size();i++){
		int ct = G[num][i];
		if(ct!=f){
			dfs1(ct,num);
			size[num]=size[ct];
		}
	}
}

int main() {
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int mst = 0,msn = 0,avi = 1;
	for(int i=1;i<=n;i++){
		if(G[i].size()>2 && msn>2)avi = 0;
		if(G[i].size()>msn){
			mst = i;
			msn = G[i].size();
		}
	}
	dfs1(mst,-1);
	if(!avi){
		cout<<"No"<<endl;
		return 0;
	}else{
		cout<<"Yes"<<endl;
		cout<<G[mst].size()<<endl;
		for(int i=0;i<G[mst].size();i++){
			int ct = G[mst][i];
			cout<<mst<<' '<<size[ct]<<endl;
		}
	}
	return 0;
}