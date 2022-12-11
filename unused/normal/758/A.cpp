#include <bits/stdc++.h>
using namespace std;

int dat[10000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);
	int ans = 0;
	for (int i = 0; i < n; i++) ans += *max_element(dat, dat + n) - dat[i];
	printf("%d", ans);
}