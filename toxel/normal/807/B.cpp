#include<bits/stdc++.h>

int p, x, y;

bool check(int mark){
	if (mark < y){
		return false;
	}
	for (int now = mark / 50 % 475, i = 0; i < 25; ++ i){
		now = (now * 96 + 42) % 475;
		if (now + 26 == p){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d%d", &p, &x, &y);
	for (int i = 0; i < 1000; ++ i){
		if (check(x - i * 50)){
			return printf("0\n"), 0;
		}
	}
	for (int i = 0; i < 1000; ++ i){
		if (check(x + i * 50)){
			return printf("%d\n", i + 1 >> 1), 0;
		}
	}
}