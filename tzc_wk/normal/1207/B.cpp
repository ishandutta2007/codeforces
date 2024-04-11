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
int n,m,a[55][55];
bool vis[55][55];
vector<pair<int,int> > ans;
int main(){
	cin>>n>>m;
	REP(i,n)	REP(j,m)	cin>>a[i][j];
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
				ans.push_back({i,j});
				vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(a[i][j]&&!vis[i][j])	return puts("-1"),0;
		}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)	cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}