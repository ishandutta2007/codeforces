#include <bits/stdc++.h>

using namespace std;

int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-')f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return num * f;
}
int n, a[1009], vis[1009];
int gcd(int a, int b){
	return (b == 0)? a : gcd(b, a % b);
}
void work(){
	int t = 0, maxn = 0;
	memset(vis, 0, sizeof(vis));
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		maxn = max(maxn, a[i]);
	}
	while(1){
		int maxn1 = 0, f = 0;
		for(int j = 1; j <= n; j++)if(!vis[j] && a[j] % maxn == 0){
			vis[j] = 1;f = 1;
			printf("%d ",a[j]);
		}
		for(int j = 1; j <= n; j++)if(!vis[j]){
			if(gcd(maxn, a[j]) > maxn1){
				maxn1 = gcd(maxn, a[j]);
				f = 1;
			}
		}
		maxn = maxn1;
		if(!f)break;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			printf("%d ",a[i]);
		}
	}
	printf("\n");
}
int main()
{
	int kase = read();
	while(kase--)work();
	return 0;
}