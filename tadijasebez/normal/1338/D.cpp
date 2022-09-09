#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
vector<int> E[N];
//int val[N],dep[N];
int dp[N][2],ans;
void DFS(int u,int p){
	dp[u][0]=(int)E[u].size()-1;
	ckmx(ans,(int)E[u].size());
	dp[u][1]=1;
	ckmx(ans,1);
	//dep[u]=dep[p]+val[u];
	vector<int> tmp[2];
	for(int v:E[u])if(v!=p){
		DFS(v,u);
		tmp[0].pb(dp[v][0]);
		tmp[1].pb(max(dp[v][1],dp[v][0]));
		ckmx(dp[u][1],dp[v][0]+1);
		ckmx(dp[u][0],max(dp[v][0],dp[v][1])+(int)E[u].size()-2);
		ckmx(ans,dp[v][0]+1);
		ckmx(ans,max(dp[v][0],dp[v][1])+(int)E[u].size()-1);
	}
	sort(tmp[0].rbegin(),tmp[0].rend());
	sort(tmp[1].rbegin(),tmp[1].rend());
	if(tmp[0].size()>1){
		ckmx(ans,tmp[0][0]+tmp[0][1]+1);
		ckmx(ans,tmp[1][0]+tmp[1][1]+(int)E[u].size()-2);
	}
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	//for(int i=1;i<=n;i++)val[i]=(int)E[i].size()-2;
	DFS(1,0);
	printf("%i\n",ans);
	/*int cen=n+1;
	dep[n+1]=-1e9;
	for(int i=1;i<=n;i++)if(E[i].size()!=1 && dep[i]>dep[cen])cen=i;
	DFS(cen,0);
	int ans=0;
	for(int i=1;i<=n;i++)ckmx(ans,dep[i]+2);
	printf("%i\n",ans);*/
	return 0;
}