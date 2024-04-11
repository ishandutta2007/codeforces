#include<bits/stdc++.h>
using namespace std;
const int N(222222);
char st[N];
int main() {
	int n, a, b, k;
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", st);
	int cnt(0);
	vector<pair<int, int> > vec;
	for(int i(0), j; i < n; i = j) {
		if(st[i] == '1') {
			j = i + 1;
			continue;
		}
		for(j = i; j < n && st[j] == '0'; j++);
		cnt += (j - i) / b;
		if(j - i >= b) {
			vec.push_back(make_pair(i, j - 1));
		}
	}
	printf("%d\n", (cnt - a + 1));
	int rmn(cnt - a + 1);
	while(rmn) {
		rmn--;
		printf("%d%c", vec.back().first + b, rmn ? ' ' : '\n');
		vec.back().first += b;
		if(vec.back().second - vec.back().first + 1 < b) {
			vec.pop_back();
		}
	}
}