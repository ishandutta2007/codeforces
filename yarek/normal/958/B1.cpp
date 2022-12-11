#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int d[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		d[u]++, d[v]++;
	}
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
		res += d[i] == 1;
	printf("%d\n", res);
	return 0;
}