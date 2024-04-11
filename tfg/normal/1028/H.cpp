#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

const int ms = 5.1e6;
const int mp = 9;
const int mn = 2e5;

int group[ms];
std::vector<int> nums[ms];
int c, d[1 << mp];
int last[mn][mp + mp];

void gen(int on, std::vector<int> &p, int v) {
	if(on == p.size()) {
		d[c++] = v;
	} else {
		gen(on + 1, p, v);
		gen(on + 1, p, v * p[on]);
	}
}

int n, q;
int table[ms][mp];
bool np[ms];

int main() {
	//std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> q;
	for(int i = 1; i < ms; i++) {
		group[i] = 1;
	}
	for(int i = 2; i < ms; i++) {
		if(!np[i]) {
			for(int j = i; j < ms; j += i) {
				int e = 0;
				int x = j;
				while(x % i == 0) {
					x /= i;
					e++;
				}
				if(e & 1) {
					group[j] *= i;
					nums[j].push_back(i);
				}
				np[j] = true;
			}
		}
	}
	/*int groups = 0;
	for(int i = 1; i < ms; i++) {
		if(group[i] == i) {
			groups++;
		}
	}
	std::cout << groups << std::endl;*/
	memset(table, -1, sizeof table);
	memset(last, -1, sizeof last);
	for(int i = 1; i <= n; i++) {
		int v;
		scanf("%d", &v);
		v = group[v];
		c = 0;
		//std::cout << "starting in " << i << ", v is " << v << std::endl;
		gen(0, nums[v], 1);
		for(int j = 0; j < mp + mp; j++) {
			last[i][j] = last[i-1][j];
		}
		for(int j = 0; j < c; j++) {
			int lul = d[j];
			//std::cout << "generated " << lul << std::endl;
			for(int k = 0; k < mp; k++) {
				if(table[lul][k] == -1) continue;
				int cost = int(nums[v].size()) - 2 * int(nums[lul].size()) + k;
				//std::cout << "to " << k << " got cost " << cost << ", last was " << table[lul][k] << std::endl;
				last[i][cost] = std::max(last[i][cost], table[lul][k]);
			}
			table[lul][nums[v].size()] = i;
		}
		for(int j = 1; j < mp + mp; j++) {
			last[i][j] = std::max(last[i][j - 1], last[i][j]);
		}
		/*std::cout << "ended:";
		for(int j = 0; j < mp + mp; j++) {
			std::cout << last[i][j] << ' ';
		}
		std::cout << std::endl;*/
	}
	while(q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = 0;
		while(last[r][ans] < l) ans++;
		printf("%d\n", ans);
	}
}