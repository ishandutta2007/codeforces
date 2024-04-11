#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;

using namespace std;

int fir[N] , ne[M] , to[M] , cnt , x , y , C[N] , col , S[N] , n;

void add(int x , int y) {
    ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

void link(int x , int y) {
    add(x , y); add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

void init(void) {
    scanf("%d" , &n);
    for(int i = 1;i < n;++ i) scanf("%d%d" , &x , &y) , link(x , y);
    for(int i = 1;i <= n;++ i) scanf("%d" , &C[i]);
}

bool dfs(int x , int f) {
    S[x] = 1;
    Foreachson(i , x) {
	int V = to[i]; if(V == f) continue;
	S[x] &= dfs(V , x);
	S[x] &= (C[V] == C[x]);
    }
    return S[x];
}

void dance(int x , int f) {
    int cur = 1;
    bool can = C[x] == C[f]; if(!f) can = 1;
    int all = 0 , d = 0;
    Foreachson(i , x)  if(to[i] != f)all += S[to[i]] & (C[x] == C[to[i]]) , ++ d;
    Foreachson(i , x) {
	int V = to[i]; if(V == f) continue;
	if(can & (all == d - 1 +  (S[V] & (C[x] == C[V])))) dance(V , x);
	cur &= S[V];
    }
    if(cur) {
	puts("YES"); cout << x << endl;
	exit(0);
    }
}

int main(void) {
    init();
    dfs(1 , 0);
    dance(1 , 0);
    puts("NO");
}