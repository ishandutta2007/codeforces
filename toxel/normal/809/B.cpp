#include<bits/stdc++.h>

const int N = 10;

std::map <std::pair <int, int>, bool> Hash;
int n, k;
char s[N];

bool query(int x, int y){
	if (Hash.count({x, y})){
		return Hash[{x, y}];
	}
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	scanf("%s", s);
	return Hash[{x, y}] = s[0] == 'T';
}

int ask(int left, int right){
	while (left < right){
		int mid = left + right >> 1;
		if (query(mid + 1, mid)){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return left;
}

int askleft(int left, int right){
	while (left < right){
		int mid = left + right >> 1;
		if (query(mid, mid + 1)){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return left;
}

int main(){
	scanf("%d%d", &n, &k);
	int x1 = ask(1, n), x2 = 0, x3 = 0;
	if (x1 > 1){
		x2 = askleft(1, x1 - 1);
	}
	if (x1 < n){
		x3 = ask(x1 + 1, n);
	}
	if ((x2 == 1 || query(x2, x2 - 1)) && query(x2, x2 + 1)){
		return printf("2 %d %d\n", x2, x1), 0;
	}
	return printf("2 %d %d\n", x1, x3), 0;
}