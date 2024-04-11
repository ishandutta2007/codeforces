#include<bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MM = 1e9 + 7;
const int MAXN = 2e6 + 10;

int a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt += a[i] == 1;
	}
	int p = n + 1;
	for (int i = 1; i <= n; i++){
		int now = a[i], q = 1, j = i + 1;
		while(j <= n && now != 1){
			now = __gcd(now, a[j]);
			q++;
			j++;
		}
		if (now == 1)
			p = min(p, q);
	}
	if (p == n + 1){
		printf("-1\n");
		return 0;
	}
	if (cnt){
		printf("%d\n", n - cnt);
	}
	else
		printf("%d\n", (p - 1) + (n - 1));
	return 0;
}