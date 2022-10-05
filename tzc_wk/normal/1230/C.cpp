#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
int n,m;
vector<int> g[10];
int a[10],ans=0;
int id(int x,int y){
	if(x>y)	swap(x,y);
	int sum=0;
	for(int i=1;i<=x-1;i++)	sum+=n-i+1;
	sum+=y;
	return sum;
}
inline void dfs(int dep){
	if(dep==n+1){
//		for(int i=1;i<=n;i++)	cout<<a[i]<<" ";
//		cout<<endl;
		bool used[30]={0};
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				for(int j=0;j<g[i].size();j++){
					int to=g[i][j];
					int x=a[to];
					if(x>0){
						if(!used[id(x,a[i])]){
							used[id(x,a[i])]=1;
							cnt++;
						}
					}
				}
			}
		}
		ans=max(ans,cnt);
		return;
	}
	for(int i=0;i<=6;i++){
		a[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}