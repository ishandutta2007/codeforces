#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

string who = "./\\";

int ans[N][N], A[N], n, tot;

bool vis[N];

int main() {
	cin >> n;
	int flag = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++ i) if(A[i] != i){
		if(vis[i]) continue;
		vector <int> cur;
		cur.clear();
		for(int x = i; !vis[x]; x = A[x]) {
			cur.push_back(x);
			vis[x] = 1;
		}
		cur.push_back(i);
		if(!flag) {
			flag = i;
			for(int i = 1; i < (int) cur.size() - 1; ++ i) {
				int a = cur[i], b = cur[i + 1];
				++ tot;
				ans[tot][a] = ans[tot][b] = 2 - (a < b);
			}
		}
		else {
			++ tot;
			ans[tot][flag] = ans[tot][cur[1]] = 1;
			for(int i = 1; i < (int) cur.size() - 1; ++ i) {
				int a = cur[i], b = cur[i + 1];
				++ tot;
				ans[tot][a] = ans[tot][b] = 2 - (a < b);
			}
			ans[tot][flag] = 2;
		}
	}
	cout << n - (!!flag) << endl;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) putchar(who[ans[i][j]]);
		puts("");
	}
}