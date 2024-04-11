#include<bits/stdc++.h>

const int N = 5010;
typedef long long ll;

int n;
int a[N], presit[N], sufsit[N];
ll pre[N], premax[N], sufmax[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		pre[i] = (i ? pre[i - 1] : 0) + a[i];
	}
	for (int i = 1; i <= n; ++ i){
		ll x = premax[i - 1] - a[i - 1];
		ll y = pre[i - 1];
		if (x > y){
			premax[i] = x;
			presit[i] = presit[i - 1];
		}
		else{
			premax[i] = y;
			presit[i] = i;
		}
	}
	sufsit[n] = n;
	for (int i = n - 1; i >= 0; -- i){
		ll x = sufmax[i + 1] + a[i];
		ll y = -(pre[n - 1] - (i ? pre[i - 1] : 0));
		if (x > y){
			sufmax[i] = x;
			sufsit[i] = sufsit[i + 1];
		}
		else{
			sufmax[i] = y;
			sufsit[i] = i;
		}
	}
	int sit = 0;
	for (int i = 0; i <= n; ++ i){
		if (premax[i] + sufmax[i] > premax[sit] + sufmax[sit]){
			sit = i;
		}
	}
	return printf("%d %d %d\n", presit[sit], sit, sufsit[sit]), 0;
}