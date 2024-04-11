#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int q , n;

int main(void) {
	for(scanf("%d",&q);q -->0;) {
		scanf("%d",&n);
		if(n == 4 || n == 6) {
			puts("1"); continue;
		}
		if(n <= 7) {
			puts("-1");
			continue;
		}
		if(n % 4 == 1) {
			printf("%d\n" , (n - 9) / 4 + 1);
		}
		else if(n % 4 == 3) {
			if(n == 11) {
				puts("-1"); continue;
			}
			printf("%d\n" , (n - 15) / 4 + 2);
		}
		else {
			printf("%d\n" , n / 4);
		}
	}
}