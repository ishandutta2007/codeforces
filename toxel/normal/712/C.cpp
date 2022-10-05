#include<bits/stdc++.h>

int x, y, a, b, c;

int main(){
	scanf("%d%d", &x, &y);
	a = b = c = y;
	int cnt = 0;
	while (true){
		if (a == x){
			break;
		}
		++ cnt;
		a = b + c - 1;
		if (a > x){
			a = x;
		}
		std::swap(a, c);
		std::swap(a, b);
	}
	return printf("%d\n", cnt), 0;
}