#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

std::multiset <ll> preset, sufset;
int n;
int a[N];
ll pre[N];

int main(){
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
		sum += a[i];
	}
	for (int i = 1; i < n; ++ i){
		preset.insert(pre[i] - (sum - pre[i]));
	}
	sufset.insert(-sum);
	for (int i = 1; i <= n; ++ i){
		if (preset.count(0) || preset.count(2 * a[i])){
			return printf("YES\n"), 0;
		}
		if (sufset.count(0) || sufset.count(2 * -a[i])){
			return printf("YES\n"), 0;
		}
		if (i < n){
			preset.erase(preset.find(pre[i] - (sum - pre[i])));
			sufset.insert(pre[i] - (sum - pre[i]));
		}
	}
	return printf("NO\n"), 0;
}