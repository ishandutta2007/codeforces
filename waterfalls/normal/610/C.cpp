#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > gen(int n) {
	if (n==0) return { { 1 } };
	if (n==1) return { { 1, 1 }, { 1, -1} };
	auto prev = gen(n-1);
	auto res = prev;
	res.insert(res.end(),prev.begin(),prev.end());
	for (int i=0;i<prev.size();i++) res[i].insert(res[i].end(),prev[i].begin(),prev[i].end());
	for (auto& v: prev) for (int& i: v) i*=-1;
	for (int i=0;i<prev.size();i++) res[i+prev.size()].insert(res[i+prev.size()].end(),prev[i].begin(),prev[i].end());
	return res;
}

int n;

int main() {
	scanf("%d",&n);
	auto ans = gen(n);
	for (auto v: ans) {
		for (int i: v) printf("%c",i==1 ? '+' : '*');
		printf("\n");
	}

	return 0;
}