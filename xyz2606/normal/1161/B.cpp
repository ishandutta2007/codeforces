#include<bits/stdc++.h>
using namespace std;
const int N(222222);
int f[N], ext[N];
vector<pair<int, int> > sgts[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		sgts[min(abs(a - b), n - abs(a - b))].push_back({a, b});
	}
	vector<int> cand;
	for(int i(1); i < n; i++) if(n % i == 0) {
		f[i] = true;
		cand.push_back(i);
	}
	int t = 0;
	for(int i(1); i <= n / 2; i++) {
		t++;
		vector<int> vec;
		for(auto tmp : sgts[i]) {
			int a = tmp.first, b = tmp.second;
			int norm;
			if((a - 1 + i) % n == b - 1) 
				norm = a;
			else norm = b;
			vec.push_back(norm);
			ext[norm] = t;
			if(i * 2 == n) ext[(norm - 1 + i) % n + 1] = t;
		}

		for(int delta : cand) {
			bool flag = true;
			for(int j : vec) {
				if(ext[(j - 1 + delta) % n + 1] != t) {
					flag = false;
					break;
				}
			}
			if(!flag) f[delta] = false;
		}
	}
	int ans = 0;
	for(int i(1); i < n; i++) ans += f[i];
	printf("%s\n", ans ? "Yes" : "No");
}