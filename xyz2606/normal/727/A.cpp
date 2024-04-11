#include<bits/stdc++.h>
using namespace std;
int a, b;
vector<long long> vec;
void dfs() {
	if(vec.back() > b) {
		return;
	}else if(vec.back() == b) {
		printf("YES\n%d\n", (int)vec.size());
		for(int i(0); i < (int)vec.size(); i++) {
			printf("%d ", vec[i]);//, i == (int)vec.size() - 1 ? '\n' : ' ');
		}
		exit(0);
	} else {
		vec.push_back(vec.back() * 2);
		dfs();
		vec.pop_back();
		vec.push_back(vec.back() * 10 + 1);
		dfs();
		vec.pop_back();
	}
}
int main() {
	cin >> a >> b;
	vec.push_back(a);
	dfs();
	printf("NO\n");
}