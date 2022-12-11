#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],b[N];
vector<int>vec[N];
bool vi[N],vis[N],pd;
void dfs(int i){
	vi[i]=vis[i]=1;
	for(auto it:vec[i]){
		if(vi[it])pd=1;
		if(!vis[it])dfs(it);
	}
	vi[i]=0;
}
int main(){
	int t;
    scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)vec[i].clear(),vis[i]=vi[i]=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)vec[a[i]].push_back(b[i]);
		int mx=1;
		for(int i=1;i<=n;i++)if(vec[i].size()>vec[mx].size())mx=i;
		vis[mx]=1;
		pd=0;
		for(int i=0;i<=n;i++)if(!vis[i])dfs(i);
        puts(pd?"WA":"AC");
	}
}