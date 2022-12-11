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

int n, m;
int cur[N];
int read[N];
int need[N];

bool ask(int a, int b){
	for(int i = 1; i <= m; ++i)
		cur[i] = 0;
	
	for(int i = a; i < b; ++i)
		cur[read[i]]++;
	
	for(int i = 1; i <= m; ++i)
		if(cur[i] != need[i])
			return false;
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &read[i]);
	
	int sum = 0;
	for(int i = 1; i <= m; ++i)
		scanf("%d", &need[i]),
		sum += need[i];
	
	bool ans = false;
	for(int i = 1; i + sum <= n + 1; ++i)
		ans |= ask(i, i + sum);
	
	puts(ans ? "YES" : "NO");
	return 0;
}