#include<bits/stdc++.h>

std::vector <int> vec, _vec;

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0, t; i < n; ++ i){
		scanf("%d", &t);
		if (t < 0){
			vec.push_back(i);
			-- k;
		}
	}
	if (k < 0){
		return printf("-1\n"), 0;
	}
	int ans = 2 * vec.size();
	for (int i = 1; i < vec.size(); ++ i){
		_vec.push_back(vec[i] - vec[i - 1] - 1);
	}
	sort(_vec.begin(), _vec.end());
	for (int i = 0; i < _vec.size(); ++ i){
		if (k < _vec[i]){
			break;
		}
		k -= _vec[i];
		ans -= 2;
	}
	if (!vec.size()){
		return printf("0\n"), 0;
	}
	if (n - vec[vec.size() - 1] - 1 <= k)
		-- ans;
	printf("%d\n", ans);
	return 0;
}