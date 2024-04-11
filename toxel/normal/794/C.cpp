#include<bits/stdc++.h>

const int N = 300010;

char a[N], b[N], ans[N];
int n;

int main(){
	scanf("%s%s", a, b);
	int n = strlen(a);
	std::sort(a, a + n);
	std::sort(b, b + n, std::greater <char>());
	int fronta = 0, backa = n - 1 >> 1, frontb = 0, backb = n - 2 >> 1, frontans = 0, backans = n - 1;
	for (int i = 0; i < n; ++ i){
		if (i & 1){
			if (a[fronta] >= b[frontb]){
				ans[backans --] = b[backb --];
			}
			else{
				ans[frontans ++] = b[frontb ++];
			}
		}
		else{
			if (a[fronta] >= b[frontb]){
				ans[backans --] = a[backa --];
			}
			else{
				ans[frontans ++] = a[fronta ++];
			}
		}
	}
	return printf("%s\n", ans), 0;
}