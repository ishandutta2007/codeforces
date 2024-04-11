#include<bits/stdc++.h>

typedef long long ll;
inline ll sqr(ll n){return n * n;}

int main(){
	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	ll x = sqr(x2 - x1) + sqr(y2 - y1), y = sqr(x3 - x2) + sqr(y3 - y2);
	return printf(1ll * (x2 - x1) * (y3 - y1) - 1ll * (x3 - x1) * (y2 - y1) && x == y ? "Yes\n" : "No\n"), 0;
}