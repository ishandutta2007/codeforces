// Author : WangZhikun
// Date   : 2018.09.03

#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}

int n,u,v,ord[1000010],cid = 2;
vector<int> G[1000010];
void dfs(int num){
	ord[num] = cid++;
	for(auto ct:G[num]){
		if(ord[ct])continue;
		ord[ct] = ord[num];
	}
}
int main(){
	read(n);
	for(int i=1;i<n;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ord[1] = 1;
	int cu = 0,ans= 1,cc;
	for(int i=0;i<n;i++){
		read(cc);
		if(ord[cc]<cu || !ord[cc])ans = 0;
		cu = ord[cc];
		dfs(cc);
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}