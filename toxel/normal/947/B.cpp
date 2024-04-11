#include<bits/stdc++.h>

typedef long long ll;
const int N = 100010;

ll v[N], t[N], pre[N];
int cnt[N];
ll ans[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%I64d", &v[i]);
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%I64d", &t[i]);
		pre[i] = pre[i - 1] + t[i];
	}
	for (int i = 1; i <= n; ++ i){
		int left = i - 1, right = n;
		while (left < right){
			int mid = left + right + 1 >> 1;
			if (v[i] < pre[mid] - pre[i - 1]){
				right = mid - 1;
			}
			else{
				left = mid;
			}
		}
		++ cnt[i];
		-- cnt[left + 1];
		ans[left + 1] += v[i] - (pre[left] - pre[i - 1]);
	}
	for (int i = 1; i <= n; ++ i){
		cnt[i] += cnt[i - 1];
		ans[i] += cnt[i] * t[i];
	}
	for (int i = 1; i <= n; ++ i){
		printf("%I64d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}