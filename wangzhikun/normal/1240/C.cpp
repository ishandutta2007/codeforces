#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,k,u,v,w;

ll dp[500050][2];
vector< pair<int,int> > G[500050];

void dfs(int num,int fa = -1){
	dp[num][0] = dp[num][1] = 0;
	vector<ll> V;
	for(auto cw:G[num]){
		if(cw.first == fa)continue;
		dfs(cw.first,num);
		V.push_back(cw.second+dp[cw.first][1]-dp[cw.first][0]);
		dp[num][0]+=dp[cw.first][0];
		dp[num][1]+=dp[cw.first][0];
	}
	//cout<<num<<"  :  ";for(auto ct:V)cout<<ct<<',';cout<<endl;
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	for(int i=0;i<V.size();i++){
		if(V[i]<0 || i == k)break;
		dp[num][0]+=V[i];
		if(i+1!=k) dp[num][1]+=V[i];
	}
}

int main() {
	int q;
	read(q);
	while(q--){
		read(n);read(k);
		for(int i=1;i<n;i++){
			read(u);read(v);read(w);
			G[u].push_back(make_pair(v,w));
			G[v].push_back(make_pair(u,w));
		}
		dfs(1);
		cout<<dp[1][0]<<endl;
		for(int i=1;i<=n;i++)G[i].clear();
	}
	return 0;
}