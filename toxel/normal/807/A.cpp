#include<bits/stdc++.h>

const int N = 1010;

int n;
int a[N], b[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &a[i], &b[i]);
		if (a[i] != b[i]){
			return printf("rated\n"), 0;
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = i + 1; j < n; ++ j){
			if (a[i] < a[j]){
				return printf("unrated\n"), 0;
			}
		}
	}
	return printf("maybe\n"), 0;
}