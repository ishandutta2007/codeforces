
// Problem : A. Carrot Cakes
// Contest : Codeforces - Playrix Codescapes Cup (Codeforces Round #413, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/799/problem/A
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, T, K, D;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T >> K >> D;
	int ans1 = (N+K-1)/K*T;
	priority_queue<int, vector<int>, greater<int>> qu;
	int ans2 = 0;
	qu.push(0);
	qu.push(D);
	//N += K;
	while(N > 0){
		int n = qu.top();
		qu.pop();
		N -= K;
		ans2 = n+T;
		qu.push(n+T);
		//cout << " " << N << "\n";
		//cout << n << "\n";
	}
	//cout << ans1 << " " << ans2 << "\n";
	if(ans1 > ans2){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}