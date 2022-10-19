#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include<vector>
using namespace std;

const int N = 100005 , M = N;

priority_queue<int>q;

int du[N] , x , y , n , m , where[N] , cnt;

vector<int>G[N];

void topo(void) {
	cnt = n + 1;
	for(int i = 1;i <= n;i ++) if(!du[i]) q.push(i);
	while(q.size()) {
		int ind = q.top(); q.pop(); where[ind] = -- cnt;
		for(int i = 0;i <(int) G[ind].size();i ++) {
			int V = G[ind][i]; du[V] --;
			if(!du[V]) q.push(V);
		}
	}
	for(int i = 1;i <= n;i ++) printf("%d ",where[i]); puts("");
}

int main(void) {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i ++) {
		scanf("%d%d",&x,&y);
		G[y].push_back(x); du[x] ++;
	}
	topo();
}