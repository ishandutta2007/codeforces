#include<bits/stdc++.h>

typedef long long ll;

ll x, y, l, r, k;

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d", &l, &r, &x, &y, &k);
	x *= k, y *= k;
	ll left = std::max(x, l);
	ll right = std::min(y, r);
	return printf(left <= right && (left / k != right / k || !(left % k)) ? "YES\n" : "NO\n"), 0;
}