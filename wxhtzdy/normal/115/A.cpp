#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> g[2020];
int dpt[2020],cnt[2020];
void cl(int n){for(int i=0;i<n;i++)cnt[i]=0;}
void dfs(int v,int pr){
	cnt[dpt[v]]++;
	for(auto c:g[v]){if(c==pr)continue;dpt[c]=dpt[v]+1;cnt[dpt[c]]++;dfs(c,v);}
}
int main(){
	int n;
	scanf("%i",&n);
	cl(n); int a[n];
	for(int i=0;i<n;i++){scanf("%i",&a[i]);if(a[i]!=-1)g[a[i]-1].pb(i);}
	for(int i=0;i<n;i++)if(a[i]==-1)dfs(i,-1);
	int sol=0;
	for(int i=0;i<n;i++)if(cnt[i]!=0)sol++;
	printf("%i",sol);
}