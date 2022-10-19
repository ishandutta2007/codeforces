#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

double  dep[N] , ans;
int n , m , x , y;
vector <int> G[N];

void dfs(int x , int f) {
    dep[x] = dep[f] + 1; ans += 1 / (dep[x]);
    for(auto V : G[x]) {
	if(V == f) continue;
	dfs(V , x);
    }
}

int main(void) {
    scanf("%d" , &n);
    for(int i = 1;i < n;++ i) {
	scanf("%d%d" , &x , &y); G[x].push_back(y); G[y].push_back(x);
    }
    dfs(1 , 0);
    printf("%.20lf\n" , ans);
}