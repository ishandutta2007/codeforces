#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef std::pair<int, int> ii;

const int ms = 5050;

int n;
int a[ms];
int val[ms][ms];

int tree[ms + ms];

void upd(int x, int v) {
	x += n;
	tree[x] = std::max(v, tree[x]);
	//std::cout << "pos " << x - n << " is now " << tree[x] << std::endl;
	for(x /= 2; x > 0; x /= 2) {
		tree[x] = std::max(tree[x + x], tree[x + x + 1]);
	}
}

int qry(int l, int r) {
	int ans = 0;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) ans = std::max(ans, tree[l++]);
		if(r & 1) ans = std::max(ans, tree[--r]);
	}
	return ans;
}

std::vector<ii> qries[ms];
int ans[int(1e5) + 10];

int main() {
	srand(time(0));
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		//a[i] = rand();
	}
	for(int i = 0; i < n; i++) {
		int msk = 0;
		while((1 << msk) <= i) msk++;
		msk = 1 << (msk - 1);
		if(i == 0) msk = 0;
		//std::cout << "msk for " << i << " is " << msk << std::endl;
		for(int j = 0; j + msk < n; j++) {
			if(i == 0) {
				val[i][j] = a[j];
			} else {
				val[i][j] = val[i^msk][j+msk] ^ val[i^msk][j];
			}
		}
	}
	/*for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			std::cout << "answer for (" << i << ", " << j << ") is " << val[j-i][i] << std::endl;
		}
	}*/
	int q;
	std::cin >> q;
	for(int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		qries[r - 1].push_back(ii(l - 1, i));
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			upd(j, val[i - j][j]);
		}
		for(auto e : qries[i]) {
			ans[e.second] = qry(e.first, i + 1);
		}
	}
	for(int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
}