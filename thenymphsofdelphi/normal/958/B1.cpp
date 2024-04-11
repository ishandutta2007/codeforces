#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n';
#define pque priority_queue
const int mod = 1000000007;

/*
10
4 3
2 6
10 1
5 7
5 8
10 6
5 9
9 3
2 9
*/

vector <int> a[1001];
bool ck[1001];
int cnt = 0;

void dfs(int u){
	ck[u] = true;
	if (a[u].size() == 1){
		cnt++;
	}
	for (int i = 0; i < a[u].size(); i++){
		if (!ck[a[u][i]]){
			dfs(a[u][i]);
		}
	}
	return;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	int n, x, y;
	cin >> n;
	for (int i = 1; i < n; i++){
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(ck, 0, sizeof ck);
	dfs(1);
	cout << cnt;
}