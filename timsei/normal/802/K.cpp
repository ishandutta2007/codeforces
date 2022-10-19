#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct NODE {
	int id , sum , into;
	friend bool operator < (NODE xxx , NODE yyy) {
		return xxx.sum > yyy.sum;
	}
};

const int N = 1e5 + 5;
const int M = N * 2;

int fir[N], ne[M] , to[M] , cnt , n , m , C[M] , x , y , k , z;
int dp[N][2];

void add(int x , int y , int z) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; C[cnt] = z;
}

void link(int x ,int y ,int z) {
	add(x , y , z); add(y , x , z);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])
#define ALL(x) x.begin() , x.end()

void dfs(int x , int f) {
	vector <NODE> d; d.clear();
	Foreachson(i , x) {
		int V = to[i];
		if(V == f) continue;
		dfs(V , x);
		d.push_back((NODE){V , dp[V][0] + C[i] , dp[V][1] + C[i]});
	}
	dp[x][0] = dp[x][1] = 0;
	sort(ALL(d));
	int tot = k - 1;
	for(int i = 0;i < min(tot , (int)d.size());++ i) dp[x][0] += d[i].sum;
	if(d.size() <= tot) {
		dp[x][1] = dp[x][0];
		int MAX = 0;
		for(int i = 0;i < (int)d.size();++ i) {
			MAX = max(MAX , d[i].into - d[i].sum);
		}
		dp[x][1] += MAX;
		return;
	}
	for(int i = 0;i < (int)d.size();++ i) {
		if(i >= tot) dp[x][1] = max(dp[x][1] , dp[x][0] + d[i].into);
		else dp[x][1] = max(dp[x][1] , dp[x][0] - d[i].sum + d[tot].sum + d[i].into);
	}
	dp[x][1] = max(dp[x][1] , dp[x][0]);
}

int main(void) {
	scanf("%d%d" , &n , &k);
	for(int i = 1;i < n;++ i) scanf("%d%d%d" , &x , &y , &z) , ++ x , ++ y ,  link(x , y , z);
	dfs(1 , 0);
	printf("%d\n" , dp[1][1]);
}