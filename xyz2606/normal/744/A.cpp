#include<bits/stdc++.h>
using namespace std;
const int N(1111);
int c[N], rela[N], siz[N];
int getr(int x) {
	int p(x);
	while(p != rela[p])
		p = rela[p];
	int p1(p); p = x;
	while(p != rela[p]) {
		int p2(rela[p]);
		rela[p] = p1;
		p = p2;
	}
	return p1;
}
int main() {
	int n, m, k;
	vector<int> blg;
	scanf("%d%d%d", &n, &m, &k);
	for(int i(1); i <= k; i++) {
		scanf("%d", &c[i]);
	}
	for(int i(1); i <= n; i++) {
		rela[i] = i;
	}
	for(int i(1); i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		rela[getr(x)] = getr(y);
	}
	for(int i(1); i <= n; i++) {
		siz[getr(i)] ++;
	}
	int fre(0);
	for(int i(1); i <= n; i++) {
		if(rela[i] == i) {
			bool flag(false);
			for(int j(1); j <= k; j++) {
				if(getr(c[j]) == i) {
					blg.push_back(siz[i]);
					flag = true;
					break;
				}
			}
			if(flag == false) {
				fre += siz[i];
			}
		}
	}
	sort(blg.begin(), blg.end());
	blg.back() += fre;
	int ans(-m);
	for(int i(0); i < (int)blg.size(); i++) {
		ans += (blg[i] * (blg[i] - 1) / 2);
	}
	printf("%d\n", ans);
}