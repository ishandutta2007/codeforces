#include<bits/stdc++.h>

typedef long long ll;
const int N = 1010;

int a[N];

int main(){
	ll p;
	int k;
	scanf("%lld%d", &p, &k);
	int d = 0;
	while (p){
		if (d & 1){
			int x = (k - p % k) % k;
			a[d ++] = x;
			p += x;
		}
		else{
			int x = p % k;
			a[d ++] = x;
			p -= x;
		}
		p /= k;
	}
	printf("%d\n", d);
	for (int i = 0; i < d; ++ i){
		printf("%d%c", a[i], " \n"[i == d - 1]);
	}
	return 0;
}