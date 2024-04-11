#include <bits/stdc++.h>
using namespace std;

const int N = 32769;

int t, n, A[N], B[N], x;
long long ans;

int calc(int i, int a, int b) {
	if(a ^ b) {
		return abs(A[i + 1] - B[i]) + abs(A[i] - B[i + 1]);
	} else {
		return abs(A[i + 1] - A[i]) + abs(B[i + 1] - B[i]);
	}
}

int dis[N], vis[N];

void rmain() {
	
	scanf("%d", &x);
	printf("%d ", dis[x]);
}

queue <int> q;

vector <int> G[N];

int main() {
	for(int i = 0; i < 32768; ++ i) 
	G[(i * 2) % 32768].push_back(i); 
	memset(dis, -1, sizeof(dis));
	dis[0] = 0;vis[0] = 1;
	q.push(0);
	while(!q.empty()) {
		int x = q.front(); 
		q.pop();
		int a = (x + 32767) % 32768;
		if(!vis[a]) {
			q.push(a);
			vis[a] = 1;
			dis[a] = dis[x] + 1;
		}
		for(auto a : G[x]) {
			if(!vis[a]) {
				vis[a] = 1;
				q.push(a);
				dis[a] = dis[x] + 1;
			}
		}
	}
	for(cin >> t; t --;) {
		rmain();
	}
}