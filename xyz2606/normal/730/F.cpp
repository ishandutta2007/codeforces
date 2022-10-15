#include<bits/stdc++.h>
using namespace std;
const int N(5555);
vector<int> f, lck[11];
int ans[N], a[N], p[N];
void spend_fre(int & tot) {
	while(tot && f.size()) {
		ans[f.back()]++;
		f.pop_back();
		tot--;
	}
}
void spend(int & tot) {
	spend_fre(tot);
	for(int i(10); i >= 1; i--) {
		while(tot && lck[i].size()) {
			tot--;
			f.insert(f.end(), i, lck[i].back());
			lck[i].pop_back();
			spend_fre(tot);
		}
	}
}
int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		p[i + 1] = a[i] / 10;
	}
	p[1] = b;
	for(int i(n); i >= 1; i--) {
		int lck_fre(p[i + 1]);
		int max_points(a[i] / 2);
		int fre(min(a[i] % 10, max_points));
		f.insert(f.end(), fre, i);
		max_points -= fre;
		for(int j(1); j <= max_points / 10; j++) {
			if(lck_fre) {
				lck_fre--;
				f.insert(f.end(), 10, i);
			}else {
				lck[10].push_back(i);
			}
		}
		max_points %= 10;
		if(max_points) {
			if(lck_fre) {
				f.insert(f.end(), max_points, i);
			}else {
				lck[max_points].push_back(i);
			}
		}
		spend(p[i]);
	}
	int tot(0);
	for(int i(1); i <= n; i++) {
		tot += a[i] - ans[i];
	}
	printf("%d\n", tot);
	for(int i(1); i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
}