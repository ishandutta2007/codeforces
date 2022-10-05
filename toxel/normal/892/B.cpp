#include<bits/stdc++.h>

const int N = 1000010;
typedef long long ll;

ll a[N];

int main(){
	int n;
	scanf("%d", &n);
	a[1] = 1;
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		-- a[std::max(0, i - x)];
		++ a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i){
		a[i] += a[i - 1];
		cnt += a[i] >= 1;
	}
	return printf("%d\n", cnt), 0;
}