#include<bits/stdc++.h>

int n;

int main(){
	scanf("%d", &n);
	int cnta = 0, cntb = 0;
	for (int i = 0, a, b; i < n; ++ i){
		scanf("%d%d", &a, &b);
		if (a > b){
			++ cnta;
		}
		else if (a < b){
			++ cntb;
		}
	}
	return printf(cnta > cntb ? "Mishka\n" : cnta == cntb ? "Friendship is magic!^^\n" : "Chris\n"), 0;
}