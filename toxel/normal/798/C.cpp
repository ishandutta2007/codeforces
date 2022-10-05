#include<bits/stdc++.h>

const int N = 100010;

int a[N];
int n;

int main(){
	scanf("%d", &n);
	int gcd;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		if (!i){
			gcd = a[i];
		}
		else{
			gcd = std::__gcd(a[i], gcd);
		}
	}
	if (gcd > 1){
		return printf("YES\n0\n"), 0;
	}
	int ans = 0;
	bool now = false;
	for (int i = 0; i < n; ++ i){
		if (a[i] & 1){
			if (!now){
				now = true;
				continue;
			}
			ans += 1;
			now = false;
			continue;
		}
		if (now){
			ans += 2;
			now = false;
			continue;
		}
	}
	if (now){
		ans += 2;
	}
	return printf("YES\n%d\n", ans), 0;	
}