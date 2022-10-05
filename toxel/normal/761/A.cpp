#include<bits/stdc++.h>

int a, b;

int main(){
	scanf("%d%d", &a, &b);
	if (!a && !b){
		return printf("NO\n"), 0;
	}
	int dif = std::abs(a - b);
	return printf(dif <= 1 ? "YES\n" : "NO\n"), 0;
}