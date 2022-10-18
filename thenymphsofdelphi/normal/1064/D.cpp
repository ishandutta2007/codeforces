#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

pair <int, int> A[2005][2005];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m, n, r, c, x, y;
	cin>>n>>m>>r>>c>>x>>y;
	char kt;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>kt;
		if (kt=='.') A[i][j]={-1,-1};
		else A[i][j]={-2,-2};
	}
	A[r][c]={0,0};
	deque <pair<int, int> > Q1, Q2;
	Q2.push_back({r, c});
	Q1.clear();
	int D[8]={1,0,-1,0,0,1,0,-1};
	while (!Q2.empty()){
		Q1=Q2;
		Q2.clear();
		pair <int, int> j;
		while (!Q1.empty()){
			j=Q1.front();
			Q1.pop_front();
			for (int i=0; i<8; i+=2) if (A[j.first+D[i]][j.second+D[i+1]].first==-1){
				A[j.first+D[i]][j.second+D[i+1]]=A[j.first][j.second];
				if (i==4) A[j.first+D[i]][j.second+D[i+1]].second++;
				else if (i==6) A[j.first+D[i]][j.second+D[i+1]].first++;
				if (i<4) Q1.push_back({j.first+D[i], j.second+D[i+1]});
				else if (A[j.first+D[i]][j.second+D[i+1]].first<=x && A[j.first+D[i]][j.second+D[i+1]].second<=y) Q2.push_back({j.first+D[i], j.second+D[i+1]});
			}
		}
	}
	int ans=0;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		if (0<=A[i][j].first && A[i][j].first<=x && 0<=A[i][j].second && A[i][j].second<=y) ans++;// cerr<<i<<' '<<j<<'\n';
	}
	cout<<ans;
}