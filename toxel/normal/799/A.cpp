#include<bits/stdc++.h>

int n, t, k, d;

int main(){
	scanf("%d%d%d%d", &n, &t, &k, &d);
	int first = (n - 1) / k * t;
	return printf(d < first ? "YES\n" : "NO\n"), 0;
}