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
int n,k,u,v,md,dep,st[100010],stn = 0,rt,ok = 1;
vector<int> G[100010];
void dfs(int num,int fa,int cd){
	if(cd>md){
		dep = num;
		md = cd;
	}
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfs(ct,num,cd+1);
	}
}
void dfsfnd(int num,int fa){
	st[stn++] = num;
	if(num == dep)rt = st[md/2];
	for(auto ct:G[num]){
		if(ct == fa)continue;
		dfsfnd(ct,num);
	}
	stn--;
}
void validate(int num,int fa,int k){
	if(k == 0){
		if(G[num].size()!=1)ok = 0;
		return;
	}
	if(G[num].size()-(fa != -1)<3)ok = 0;
	for(auto ct:G[num]){
		if(ct == fa)continue;
		validate(ct,num,k-1);
	}
}
int main() {
	read(n);read(k);
	
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	md = -1;
	dfs(1,-1,0);
	int cc = dep,dd;
	//cout<<cc<<endl;
	md = -1;
	dfs(cc,-1,0);
	dd = dep;
	//cout<<dd<<endl;
	if(md%2){
		cout<<"No"<<endl;
		return 0;
	}
	dfsfnd(cc,-1);
	//cout<<rt<<endl;
	validate(rt,-1,k);
	if(ok){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}