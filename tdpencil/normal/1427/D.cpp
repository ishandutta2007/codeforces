#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 52;
int n, x[N + 1], y[N + 1];
vector<vector<int> > an;

void fix(vector<int> const &v){
	int a = 0, b = n;
	for (int i = v.size() - 1; i >= 0; --i){
		int t = v[i];
		while (t)y[++a] = x[b - t + 1], --t;
		b -= v[i];
	}
	f(i, 1, n + 1)x[i] = y[i];
}

bool go(){
	int k = 1;
	f(i, 1, n + 1)if (x[i] == k)++k, i = 0;
	else if (x[i] == k + 1){
		int j = i + 1;
		while (x[j] == x[j - 1] + 1)++j;
		vector<int> v;
		if (i > 1)v.push_back(i - 1);
		v.push_back(j - i);
		i = j;
		while (x[j] != k)++j;
		v.push_back(j - i + 1);
		if (j < n)v.push_back(n - j);
		fix(v);
		an.emplace_back(v);
		return true;
	}
	return false;
}

int main(){
	scanf("%d", &n);
	f(i, 1, n + 1)scanf("%d", x + i);
	do {} while (go());
	printf("%d\n", (int)an.size());
	for (auto &v: an){
		printf("%d", (int)v.size());
		for (int u: v)printf(" %d", u);
		printf("\n");
	}
}