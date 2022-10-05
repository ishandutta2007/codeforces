#include<bits/stdc++.h>

bool firstwin(int odd, int even, int k, int first){
	if (!k){
		return !first;
	}
	int times = k >> 1;
	if (odd <= times){
		if ((odd & 1) == first){
			return true;
		}
	}
	if (even <= times){
		if ((k - even & 1) == first){
			return true;
		}
	}
	return false;
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int odd = 0, even = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		odd += x & 1;
		even += !(x & 1);
	}
	k = n - k;
	int first = !(odd & 1);
	bool flag = false;
	if (!(k & 1)){
		flag = firstwin(odd, even, k, first);
	}
	else{
		-- k;
		if (odd){
			-- odd;
			if (!firstwin(odd, even, k, first)){
				flag = true;
			}
			++ odd;
		}
		if (even){
			-- even;
			if (!firstwin(odd, even, k, first ^ 1)){
				flag = true;
			}
			++ even;
		}
	}
	return printf(flag ? "Stannis\n" : "Daenerys\n"), 0;
}