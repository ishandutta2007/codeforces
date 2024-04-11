#include<bits/stdc++.h>

const int N = 2010;
typedef long long ll;
typedef std::pair <ll, ll> pii;

ll n, k, p;
ll a[N], b[N], left[N], right[N];
pii pp[N];
std::priority_queue <int> pq;

bool check(ll mid){
	memset(left, 0x7f, sizeof(left));
	memset(right, 0, sizeof(right));
	for (ll i = 0; i < n; ++ i){
		for (ll j = 0; j < k; ++ j){
			if (std::abs(a[i] - b[j]) + std::abs(b[j] - p) <= mid){
				left[i] = std::min(left[i], j);
				right[i] = std::max(right[i], j);
			}
		}
	}
	for (ll i = 0; i < n; ++ i){
		if (left[i] > right[i]){
			return false;
		}
		pp[i] = {left[i], right[i]};
	}
	std::sort(pp, pp + n);
	while (!pq.empty()){
		pq.pop();
	}
	for (int i = 0, j = 0; i < k; ++ i){
		while (j < n && pp[j].first == i){
			pq.push(-pp[j ++].second);
		}
		if (!pq.empty()){
			if (-pq.top() < i){
				return false;
			}
			pq.pop();
		}
	}
	return pq.empty();
}
	

int main(){
	scanf("%I64d%I64d%I64d", &n, &k, &p);
	for (ll i = 0; i < n; ++ i){
		scanf("%I64d", &a[i]);
	}
	std::sort(a, a + n);
	for (ll j = 0; j < k; ++ j){
		scanf("%I64d", &b[j]);
	}
	std::sort(b, b + k);
	ll left = 0, right = 1e10;
	while (left < right){
		ll mid = left + right >> 1;
		if (check(mid)){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return printf("%I64d\n", left), 0;
}