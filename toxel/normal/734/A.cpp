#include<bits/stdc++.h>

int main(){
	int a = 0, b = 0, n;
	scanf("%d", &n);
	getchar();
	for (int i = 0, ch; i < n; ++ i){
		ch = getchar();
		ch == 'A' ? ++ a : ++ b;
	}
	if (a > b){
		return printf("Anton\n"), 0;
	}
	if (a == b){
		return printf("Friendship\n"), 0;
	}
	return printf("Danik\n"), 0;
}