#include<bits/stdc++.h>

const int N = 100010;

int a[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	int mex = 1;
	std::sort(a, a + n);
	for (int i = 0; i < n; ++ i){
		if (a[i] >= mex){
			a[i] = mex ++;
		}
	}
	return printf("%d\n", mex), 0;
}