#include<bits/stdc++.h>

const int N = 1010;

char s[N];

int query(){
	printf("? %s\n", s);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		s[i] = '0';
	}
	int first = query();
	s[0] = '1';
	int second = query();
	bool flag = second < first;
	int pos0 = 0, left = 1, right = n - 1;
	while (left < right){
		int mid = left + right >> 1;
		for (int i = 0; i <= mid; ++ i){
			s[i] = '1';
		}
		for (int i = mid + 1; i < n; ++ i){
			s[i] = '0';
		}
		int x = query();
		if (std::abs(first - x) == mid + 1){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	if (flag){
		std::swap(pos0, left);
	}
	printf("! %d %d\n", pos0 + 1, left + 1);
	fflush(stdout);
	return 0;
}