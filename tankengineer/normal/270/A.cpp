#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a;
		scanf("%d", &a);
		bool flag = true;
		for (int i = 3; i < 361; ++i) {
			if (360 % i == 0 && a == 180 - 360 / i) {
				flag = false;
			}
		}
		puts(flag ? "NO" : "YES");
	}	
	return 0;
}