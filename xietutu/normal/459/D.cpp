#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
#include <cstring>
const int maxn = 1000005;
std::multiset<int> T1,T2;
int n,left[maxn],right[maxn],a[maxn],b[maxn],s[maxn],tot[maxn];
long long ans;
void add(int x) {
	while (x <= n) {
		++s[x];	
		x += x & (-x);
	}
}
int query(int x) {
	int sum = 0;
	while (x) {
		sum += s[x];
		x -= x & (-x);
	}
	return sum;
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%d",a + i),b[i] = a[i];
	std::sort(b + 1,b + n + 1);
	
	for (int i = 1; i <= n; ++i) 
		a[i] = std::lower_bound(b + 1,b + n + 1,a[i]) - b;
		
	for (int i = 1; i <= n; ++i) {
		++tot[a[i]];
		left[i] = tot[a[i]];
	}
	
	memset(tot,0,sizeof(tot));
	for (int i = n; i >= 1; --i) {
		++tot[a[i]];
		right[i] = tot[a[i]];
	}
	add(right[n]);
	for (int i = n - 1; i >= 1;	--i) {
		if (left[i] > 1) ans = ans + query(left[i] - 1);
		add(right[i]);
	}
	std::cout << ans;
}