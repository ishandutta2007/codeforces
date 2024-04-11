#include<bits/stdc++.h>

const int N = 500010;

int boy[2][N];
std::pair <int, int> first, second;
int n, test;

int main(){
	scanf("%d%d", &n, &test);
	for (int i = 0; i < n >> 1; ++ i){
		boy[0][i] = i << 1 | 1;
		boy[1][i] = i + 1 << 1;
	}
	first = {0, 0};
	second = {1, 0};
	int moder = n >> 1;
	while (test --){
		int op, x;
		scanf("%d", &op);
		if (op == 2){
			std::swap(first, second);
			continue;
		}
		scanf("%d", &x);
		if (x & 1){
			first.first ^= 1;
			second.first ^= 1;
			int pfirst = first.second, psecond = second.second;
			if (x > 0){
				first.second = (psecond - 1 + moder) % moder;
				second.second = pfirst;
				-- x;
			}
			else{
				first.second = psecond;
				second.second = (pfirst + 1) % moder;
				++ x;
			}
		}
		first.second = ((first.second - x / 2) % moder + moder) % moder;
		second.second = ((second.second - x / 2) % moder + moder) % moder;
	}
	for (int i = 0; i < n >> 1; ++ i){
		printf("%d %d ", boy[first.first][(first.second + i) % moder], boy[second.first][(second.second + i) % moder]);
	}
	putchar('\n');
	return 0;
}