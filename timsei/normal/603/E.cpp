#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cassert>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 3;

int n , m , fa[N] , S[N] , cnt , l , r , ans[M];

struct Edge {
	int x , y , w , id;
	friend bool operator < (Edge xxx , Edge yyy) {
		return (xxx.w != yyy.w) ?  xxx.w < yyy.w : xxx.id < yyy.id;
	}
	void input(int who) {
		scanf("%d%d%d" , &x , &y , &w);
		id = who;
	}
}E[M] , val[M];

int getf(int x) {
	return (fa[x] == x) ? x : getf(fa[x]);
}

int tot;

struct opt {
	int x , y , val;
	void back(void) {
		fa[x] = x; S[y] -= S[x];
		if((S[x] & 1) && (S[y] & 1))cnt += val;
	}
}all[M];

#define o(x , y , val) (opt) {x , y , val}

void merge(int x , int y) {
	x = getf(x); y = getf(y);
	if(x == y) return;
	if(S[x] > S[y]) swap(x , y);
	int wh = 0;
	if((S[x] & 1) && (S[y] & 1)) cnt -= 2 , wh = 2;
	all[++ tot] = o(x , y , wh);
	fa[x] = y;
	S[y] += S[x];
}

void ret(int where) {
	while(tot > where) all[tot --].back();
}

void init(void) {
	for(int i = 1;i <= n;++ i) fa[i] = i , S[i] = 1;
	cnt = n;
}

void dance(int l , int r , int lo , int hi) {
	if(l > r) return;
	int door = tot , mid = (l + r) >> 1;
	for(int i = l;i <= mid;++ i) if(E[i].w < lo) merge(E[i].x , E[i].y);
	ans[mid] = -1;
	for(int i = lo;i <= hi;++ i) {
		if(val[i].id <= mid) merge(val[i].x , val[i].y);
		if(!cnt) {
			ans[mid] = i; break;
		}
	}
	ret(door);
	if(ans[mid] == -1) {
		for(int i = l;i <= mid;++ i) ans[i] = -1;
		for(int i = l;i <= mid;++ i) if(E[i].w < lo) merge(E[i].x , E[i].y);
		dance(mid + 1 , r , lo , hi);
		ret(door);
		return;
	}
	for(int i = l;i <= mid;++ i) if(E[i].w < lo) merge(E[i].x, E[i].y);
	dance(mid + 1 , r , lo , ans[mid]); ret(door);
	for(int i = lo;i < ans[mid]; ++ i) if(val[i].id < l) merge(val[i].x, val[i].y);
	dance(l , mid - 1 , ans[mid] , hi); ret(door);
}

int main(void) {
	scanf("%d%d" , &n , &m);
	init();
	if(n % 2) {
		for(int i = 1;i <= m;++ i) puts("-1");
		return 0;
	}
	for(int i = 1;i <= m;++ i) {
		E[i].input(i); val[i] = E[i];
	}
	sort(val + 1 , val + m + 1);
	for(int i = 1;i <= m; ++ i) E[val[i].id].w = i;
//	for(int i = 1;i <= m;++ i) cerr << E[i].w << endl;
	dance(1 , m , 1 , m);
	for(int i = 1;i <= m;++ i) {
		if(ans[i] == -1) {
			puts("-1"); continue;
		}
		printf("%d\n" , val[ans[i]].w);
	}
}