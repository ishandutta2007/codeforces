#include<bits/stdc++.h>

int a, b, c;

int main(){
	scanf("%d%d%d", &a, &b, &c);
	int max = std::min(std::min(a, b / 2), c / 4);
	return printf("%d\n", max * 7), 0;
}