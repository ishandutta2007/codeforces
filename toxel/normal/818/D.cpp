#include<bits/stdc++.h>

const int N = 1000001;

int a[N];
int n, A;
std::vector <int> vec[N];

int main(){
	scanf("%d%d", &n, &A);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		vec[a[i]].push_back(i);
	}
	for (int i = 1; i < N; ++ i){
		if (i == A || vec[i].size() < vec[A].size()){
			continue;
		}
		bool flag = true;
		for (int j = 0, sz = vec[A].size(); j < sz; ++ j){
			if (vec[i][j] > vec[A][j]){
				flag = false;
				break;
			}
		}
		if (flag){
			return printf("%d\n", i), 0;
		}
	}
	return printf("-1\n"), 0;
}