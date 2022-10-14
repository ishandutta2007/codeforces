// Author: Zhikun
// 2018.07.18

#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 200020

using namespace std;
typedef long long ll;

int n,u,v,a[N],vis[N] = {0},p[N] = {0},pn = 0,good[N],vised[N];
ll ans[N] = {0},H[N] = {0};
int prim[N],mu[N],cnt;
void get_mu(ll n){
	mu[1] = 1;
	for(int i=2;i<n;i++){
		if(!vis[i]){mu[i] = -1;prim[++cnt] = i;}
		for(ll j=1;j<=cnt&&prim[j]*i<=n;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0) break;
			else mu[prim[j]*i] = -mu[i];
		}
	}
}
vector<int> G[N],Q[N];
ll dfs(int num,int col,int fa){
	ll ret = 1;
	vised[num] = col;
	for(auto ct:G[num])if(good[a[ct]] == col&&ct!=fa)ret+=dfs(ct,col,num);
	return ret;
}
int main(){
	get_mu(200010);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]+=1;
		Q[a[i]].push_back(i);
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=200010;i++){
		for(int j=i;j<=200010;j+=i)good[j] = i;
		for(int j=i;j<=200010;j+=i){
			for(auto x: Q[j])if(vised[x]!=i){
				ll cu = dfs(x,i,-1);
				H[i]+=cu*(cu-1)/2;
			}
		}
	}
	for(ll i=1;i<=200010;i++){
		for(ll j=i,k=1;j<=200010;j+=i,k+=1)ans[i]+=H[j]*mu[k];
		if(ans[i]){
			cout<<i<<' '<<ans[i]<<endl;
		}
	}
	
	return 0;
}