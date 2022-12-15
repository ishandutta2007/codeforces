
// Problem : C. Fountains
// Contest : Codeforces - Playrix Codescapes Cup (Codeforces Round #413, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/799/problem/C
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, C, D;
pair<int, int> arr[2][100005];
int sz[100005];
int mx[100005];

int solve(int t, int lim){
	for(int i = 1; i<=sz[t]; i++){
		mx[i] = max(mx[i-1], arr[t][i].second);
		//arr[t][i].second = max(arr[t][i].second, arr[t][i-1].second);
	}
	int ret = 0;
	for(int i = 2; i<=sz[t]; i++){
		int idx = upper_bound(arr[t]+1, arr[t]+i, make_pair(lim - arr[t][i].first + 1, 0)) - arr[t];
		idx--;
		if(idx){
			ret = max(ret, arr[t][i].second + mx[idx]);
		}
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> C >> D;
	int mx1 =-1, mx2 = -1;
	for(int i = 1; i<=N; i++){
		int n, c;
		char t;
		cin >> n >> c >> t;
		if(t == 'C'){
			sz[0]++;
			arr[0][sz[0]].first = c;
			arr[0][sz[0]].second = n;
			if(c <= C){
				mx1 = max(mx1, n);
			}
		}
		else{
			sz[1]++;
			arr[1][sz[1]].first = c;
			arr[1][sz[1]].second = n;
			if(c <= D){
				mx2 = max(mx2, n);
			}
		}
	}
	sort(arr[0]+1, arr[0]+1+sz[0]);
	sort(arr[1]+1, arr[1]+1+sz[1]);
	int ans = 0;
	if(mx1 >= 0 && mx2 >= 0){
		ans = mx1+mx2;
	}
	ans = max(ans, solve(0, C));
	ans = max(ans, solve(1, D));
	cout << ans << "\n";
}