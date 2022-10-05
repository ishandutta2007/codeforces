#include<bits/stdc++.h>

int c, v0, v1, a, l;

int main(){
	scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l);
	int ans = 0;
	while (true){
		c -= v0;
		++ ans;
		if (c <= 0){
			break;
		}
		c += l;
		v0 = std::min(v0 + a, v1);
	}
	return printf("%d\n", ans), 0;
}