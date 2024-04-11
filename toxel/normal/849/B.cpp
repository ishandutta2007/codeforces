#include<bits/stdc++.h>

typedef long long ll;
const int N = 1010;

int y[N];
int n;

ll det(int x1, int y1, int x2, int y2){
	return 1ll * x1 * y2 - 1ll * y1 * x2;
}

bool onSeg(int x1, int y1, int x2, int y2, int x3, int y3){
	return !det(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &y[i]);
	}
	bool flag = true;
	for (int i = 2; i < n; ++ i){
		if (!onSeg(0, y[0], 1, y[1], i, y[i])){
			flag = false;
			break;
		}
	}
	if (flag){
		return printf("No\n"), 0;
	}
	flag = true;
	for (int i = 3; i < n; ++ i){
		if (!onSeg(1, y[1], 2, y[2], i, y[i])){
			flag = false;
			break;
		}
	}
	if (flag){
		return printf("Yes\n"), 0;
	}
	for (int i = 1; i < n; ++ i){
		std::vector <int> vec;
		for (int j = 1; j < n; ++ j){
			if (j == i){
				continue;
			}
			if (!onSeg(0, y[0], i, y[i], j, y[j])){
				vec.push_back(j);
			}
		}
		if (vec.size() == 1){
			return printf("Yes\n"), 0;
		}
		bool flag = true;
		for (int j = 1, sz = vec.size(); j < sz; ++ j){
			if (!onSeg(0, 0, i, y[i] - y[0], vec[j] - vec[0], y[vec[j]] - y[vec[0]])){
				flag = false;
				break;
			}
		}
		if (flag){
			return printf("Yes\n"), 0;
		}
	}
	return printf("No\n"), 0;
}