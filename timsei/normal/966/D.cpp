#include <bits/stdc++.h>
using namespace std;

const int N = 551111;
const int M = N * 2;

int n , m , x , y , fir[N] , ne[M] , to[M] , cnt = 1 , pre[N];
int dis[N] , du[N];
int vis[N];

void add(int x , int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x , int y) {
	add(x , y);
	add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

queue <int> q;

void BFS(void) {
	for(int i = 1;i <= n;++ i) dis[i] = 1e9;
	dis[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int ind = q.front();
		q.pop();
		Foreachson(i , ind) {
			int V = to[i];
			if(dis[V] == 1e9) {
				q.push(V);
				dis[V] = dis[ind] + 1;
				pre[V] = ind;
			}
		}
	}
}

void print(int x) {
	if(pre[x]) 
	print(pre[x]);
	printf("%d " , x);
}

void read(int &x) {
	char ch = getchar();
	x = 0;
	while(!isdigit(ch)) {
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
}

map<int , bool> way[N];

vector <int> B;

void dfs(int x , int y) {
	if(vis[x]) 
	return;
	vis[x] = y;
	B.push_back(x);
	Foreachson(i , x) {
		int V = to[i];
		if(dis[V] != 1)
		continue;
		dfs(V , y);
		++ du[x];
	}
}

main(void) {
	cin >> n >> m;
	for(int i = 1;i <= m;++ i) {
		scanf("%d%d" , &x , &y);
		link(x , y);
	}
	BFS();
	if(dis[n] <= 4) {
		cout << dis[n] << endl;
		print(n);
		return 0;
	}
	for(int i = 1;i <= n;++ i)
	if(dis[i] == 2) {
		cout << 4 << endl;
		cout << 1 <<" "<< pre[i] <<" "<< i <<" "<< 1 <<" "<< n << endl;
		return 0;
	}
	int tot = 0;
	memset(vis , 0 , sizeof(vis));
	for(int i = 1;i <= n;++ i) {
		if(dis[i] == 1) {
			if(!vis[i]) {
				B.clear();
				dfs(i , ++ tot);
				for(int j = 0;j < (int) B.size();++ j) {
					int V = B[j];
					if(du[V] != B.size() - 1) {
						q.push(V);
						for(int k = 1;k <= n;++ k)
						dis[k] = 1e9;
						dis[V] = 0;
						while(!q.empty()) {
							int ind = q.front();
							q.pop();
							Foreachson(k , ind) {
								int V = to[k];
								if(V == 1)
								continue;
								if(dis[V] == 1e9)
								dis[V] = dis[ind] + 1;
								else continue;
								q.push(V);
								pre[V] = ind;
							}
						}
						for(int k = 1;k <= n;++ k) {
							if(dis[k] == 2) {
								cout << 5 << endl;
								cout << 1 <<" "<< V <<" "<< pre[k] <<" "<< k <<" "<< V <<" "<< n << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	if(!pre[n]) {
		puts("-1");
		return 0;
	}
	else {
		cout << dis[n] << endl;
		print(n);	
	}
}