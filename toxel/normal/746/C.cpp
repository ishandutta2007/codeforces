#include<bits/stdc++.h>

int s, x1, x2, t1, t2, p, d;

int main(){
	scanf("%d%d%d%d%d%d%d", &s, &x1, &x2, &t1, &t2, &p, &d);
	int ans1 = std::abs(x2 - x1) * t2, ans2;
	if (x1 > p){
		if (d == 1){
			ans2 = (x1 - p) * t1;
		}
		else{
			ans2 = (x1 + p) * t1;
			d = -d;
		}
	}
	else if (x1 == p){
		ans2 = 0;
	}
	else{
		if (d == 1){
			ans2 = (2 * s - x1 - p) * t1;
			d = -d;
		}
		else{
			ans2 = (p - x1) * t1;
		}
	}
	if (x2 > x1){
		if (d == 1){
			ans2 += (x2 - x1) * t1;
		}
		else{
			ans2 += (x1 + x2) * t1;
			d = -d;
		}
	}
	else{
		if (d == 1){
			ans2 += (2 * s - x1 - x2) * t1;
			d = -d;
		}
		else{
			ans2 += (x1 - x2) * t1;
		}
	}
	return printf("%d\n", std::min(ans1, ans2)), 0;
}