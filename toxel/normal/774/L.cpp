#include<bits/stdc++.h>

const int N = 200010;

int n, k;
char s[N];
std::vector <int> vec;

bool check(int mid){
	int cnt = 0, now = 0;
	for (int i = 0; i < vec.size() - 1; ++ i){
		if (vec[i + 1] - vec[i] > mid){
			return false;
		}
		if (now + vec[i + 1] - vec[i] <= mid){
			++ cnt;
			now += vec[i + 1] - vec[i];
		}
		else{
			now = vec[i + 1] - vec[i];
		}
	}
	return cnt + k > vec.size();
}

int main(){
	scanf("%d%d%s", &n, &k, s);
	for (int i = 0; i < n; ++ i){
		if (s[i] == '0'){
			vec.push_back(i);
		}
	}
	int left = 0, right = n;
	while (left < right){
		int mid = left + right >> 1;
		if (check(mid)){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return printf("%d\n", left - 1), 0;
}