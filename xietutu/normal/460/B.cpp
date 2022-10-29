#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
typedef long long ll;
ll a,b,c,num,ans[85];
ll pow(ll x) {
	ll s = 1;
	for (int i = 1; i <= a; ++i) s = s * x;
	return s;
}
int check(ll x) {
	ll s = pow(x) * b+ c;
	if (s < 0 || s >= 1000000000) return 0; 	
	ll ss = 0,xx = s;
	while (xx) {
		ss = ss + xx % 10;
		xx = xx / 10;
	}
	return ss == x ? s : 0;
}
int main() {
	std::cin >> a >> b >> c;
	for (int i = 1; i <= 81; ++i) 
		if (check(i)) ++num,ans[num] = check(i);
	printf("%d\n",num);
	std::sort(ans + 1,ans + num + 1);
	for (int i = 1; i <= num; ++i) printf("%d ",ans[i]);
}