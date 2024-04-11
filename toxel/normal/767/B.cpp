#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

std::map <ll, std::pair <int, int>> Hash;
ll n, ts, tf, t, a[N], end[N];

int main(){
	scanf("%I64d%I64d%I64d%I64d", &ts, &tf, &t, &n);
	ll ans = -1;
	for (int i = 0; i < n; ++ i){
		scanf("%I64d", &a[i]);
		if (a[i] >= tf){
			n = i;
			break;
		}
		if (!i){
			if (a[0] < ts){
				end[i] = ts + t;
			}
			else{
				end[i] = a[0] + t;
			}
		}
		else if (a[i] >= end[i - 1]){
			end[i] = a[i] + t;
		}
		else{
			end[i] = end[i - 1] + t;
		}
		if (i && end[i - 1] < a[i]){
			ans = end[i - 1];
		}
	}
	if (a[0] > ts || !n){
		return printf("%I64d\n", ts), 0;
	}
	if (ans != -1){
		return printf("%I64d\n", ans), 0;
	}
	if (end[n - 1] + t <= tf){
		return printf("%I64d", end[n - 1]), 0;
	}
	ll min = LLONG_MAX;
	for (int i = 0; i < n; ++ i){
		if (end[i] > tf){
			break;
		}
		ll x = end[i] - a[i] + 1;
		if (x < min){
			min = x;
			ans = a[i] - 1;
		}
	}
	return printf("%I64d\n", ans), 0;
}