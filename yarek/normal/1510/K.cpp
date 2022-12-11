#include <bits/stdc++.h>

using namespace std;

const int INF = 3005;

int n;
vector <int> input;

void Move(vector <int> &cur, int type) {
	if(type == 0) {
		for(int i = 0; i < n; ++i)
			swap(cur[i], cur[i + n]);
	} else {
		for(int i = 0; i < n + n; i += 2)
			swap(cur[i], cur[i + 1]);
	}
}

int check(int shift) {
	vector <int> cur = input;
	vector <int> goal(n + n);
	iota(goal.begin(), goal.end(), 1);
	
	if(cur == goal)
		return 0;
	
	for(int round = 1; round <= INF; ++round) {
		Move(cur, (round + shift) & 1);
		if(cur == goal)
			return round;
	}
	
	return INF;
}

int main() {
	scanf("%d", &n);
	input.resize(n + n);

	for(auto &v: input)
		scanf("%d", &v);
	
	int resa = check(0);
	int resb = check(1);
	int res = min(resa, resb);
	
	if(res == INF) res = -1;
	printf("%d\n", res);
	return 0;
}