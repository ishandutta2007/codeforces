#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N, K, cnt;
vector<int> G[n];
bool vis[n];

void dfs(int cur){
	vis[cur] = true;
	cnt++;
	for(int x : G[cur]){
		if(!vis[x])
			dfs(x);
	}
}

int main(){
	cin >> N >> K;
	for(int i=0; i<K; i++){
		int x, y;
		x--; y--;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	int sum = 0;
	for(int i=0; i<N; i++){
		cnt = 0;
		if(!vis[i])
			dfs(i);
		if(cnt > 1)
			sum += cnt-1;
	}
	cout << K-sum << endl;

  return 0;
}