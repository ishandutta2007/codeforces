#include <bits/stdc++.h>

using namespace std;

int n;

bool valid(vector<int> p) {
	for (int i = 2; i < p.size(); i++)
		if(p[i] == p[i - 2] + p[i - 1] + 1)
			return false;
	return true;
}

void solve() {
	scanf("%d", &n);
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	int m = n;
	swap(p[1], p[2]);
	do {
		if(valid(p)) {
			for (int i = 0; i < n; i++)
				printf("%d ", p[i] + 1);
			printf("\n");
			m--;
		}
		if(!m)
			break;
	} while(next_permutation(p.begin(), p.end()));
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}