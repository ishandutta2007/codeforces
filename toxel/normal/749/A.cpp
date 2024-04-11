#include<bits/stdc++.h>

int n;
std::vector <int> vec;

int main(){
	scanf("%d", &n);
	int cnt = 0;
	if (n & 1){
		vec.push_back(3);
		++ cnt;
		n -= 3;
	}
	while (n){
		vec.push_back(2);
		++ cnt;
		n -= 2;
	}
	printf("%d\n", cnt);
	for (int i = vec.size() - 1; i >= 0; -- i){
		printf("%d ", vec[i]);
	}
	return 0;
}