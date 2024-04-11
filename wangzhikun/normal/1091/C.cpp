#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n,cn,pri[40],app[40] = {0},pn = 0;
vector<ll> ans;
void dfs(ll cu,ll dep){
	//cout<<cu<<' '<<dep<<endl;
	if(dep == pn){
		ll cc = n/cu;
		ans.push_back(cc+(cc*(cc-1)/2)*cu);
		return;
	}
	for(int i=0;i<=app[dep];i++){
		dfs(cu,dep+1);
		cu*=pri[dep];
	}
}
int main() {
	cin>>n;
	cn = n;
	for(int i=2;i*i<=cn;i++){
		if(cn%i == 0){
			pri[pn] = i;
			while(cn%i == 0){
				cn/=i;
				app[pn]++;
			}
			pn++;
		}
	}
	if(cn!= 1){
		pri[pn] = cn;
		app[pn]++;
		pn++;
	}
	dfs(1,0);
	sort(ans.begin(),ans.end());
	for(auto ct:ans)cout<<ct<<' ';
	return 0;
}