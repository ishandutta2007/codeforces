#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n , m , x , y , q , ty , a , b , c , s , k;

vector <int> G[N];
bool vis[N];

int rt[N * 200] , sz , ch[N * 200][2] , Min[N * 200];

void add(int x , int y) {
	if(!rt[x]) 
	rt[x] = ++ sz , Min[sz] = y;
	int now = rt[x];
	Min[now] = min(Min[now] , y);
	for(int i = 18;i >= 0;-- i) {
		int dir = 0;
		if((1 << i) & y) {
			dir = 1;
		}
		if(!ch[now][dir]) {
			ch[now][dir] = ++ sz;
			Min[sz] = y;
		}
		now = ch[now][dir];
		Min[now] = min(Min[now] , y);
	}
}

int query(int a , int b , int c) {
	int now = rt[a];
	if(!now)
	return -1;
	if(Min[now] > c)
	return -1;
	int res = 0;
	for(int i = 18;i >= 0;-- i) {
		int dir = 0;
		if((1 << i) & b)
		dir = 1;
		dir ^= 1;
		if(!ch[now][dir] || Min[ch[now][dir]] > c) {
			dir ^= 1;
		}
		res += dir * (1 << i);
		now = ch[now][dir];
	}
	return res;
}

main(void) {
	for(int i = 1;i <= 100000; ++ i) {
		for(int j = i;j <= 100000;j += i) {
			G[j].push_back(i);
		}
	}
	for(scanf("%d" , &q);q --;) {
		scanf("%d" , &ty);
		if(ty == 1) {
			scanf("%d" , &x);
			if(vis[x])
			continue;
			vis[x] = 1;
			for(int j = 0;j < (int) G[x].size();++ j)
			add(G[x][j] , x);
		}
		else if(ty == 2) {
			scanf("%d%d%d" , &x , &k , &s);
			if(x % k != 0) {
				puts("-1");
				continue;
			}
			printf("%d\n" , query(k , x , s - x));
		}
	}
}