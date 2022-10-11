#include <iostream>
#include <vector>
#include <cstdio>

const int ms = 1 << 14;

bool table[2][ms];
int rep[2][ms];
int par[2 * ms];

std::vector<int> buffer, got;
int step[2 * ms];

int ans = 0;

int get() {
	ans++;
	int ans = buffer.back();
	//std::cout << "allocated " << ans << "\n";
	buffer.pop_back();
	got.push_back(ans);
	par[ans] = ans;
	return ans;
}

int get_par(int x) {
	if(par[x] == x) {
		return x;
	} else {
		return par[x] = get_par(par[x]);
	}
}

void make_union(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if(a == b) {
		return;
	}
	ans--;
	par[b] = a;
}

char buf[ms];

int main() {
	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(NULL);
	for(int i = 0; i < 2 * ms; i++) {
		buffer.push_back(i);
	}
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf(" %s", buf);
		for(int j = 0; j < m / 4; j++) {
			char c = buf[j];
			int cur;
			if(c >= '0' && c <= '9') {
				cur = c - '0';
			} else {
				cur = c - 'A' + 10;
			}
			for(int k = 0; k < 4; k++) {
				table[i&1][4*j+k] = ((1 << (3 - k)) & cur) ? true : false; 
			}
		}
		for(int j = 0; j < m; j++) {
			if(!table[i&1][j]) {
				continue;
			}
			if(j && table[i&1][j - 1]) {
				rep[i&1][j] = rep[i&1][j - 1];
			} else if(table[(i+1)&1][j]) {
				rep[i&1][j] = rep[(i+1)&1][j];
				continue;
			} else {
				//std::cout << "for position (" << i - 1 << ", " << j << ") ";
				rep[i&1][j] = get();
			}
			if(table[(i+1)&1][j]) {
				make_union(rep[(i+1)&1][j], rep[i&1][j]);
			}
		}
		for(int j = 0; j < m; j++) {
			if(!table[i&1][j]) {
				continue;
			}
			rep[i&1][j] = get_par(rep[i&1][j]);
			//std::cout << "position (" << i - 1 << ", " << j << ") got " << rep[i&1][j] << "\n";
			step[rep[i&1][j]] = i;
		}
		for(int j = 0; j < got.size(); j++) {
			int cur = got[j];
			if(step[cur] != i) {
				buffer.push_back(cur);
				got[j] = got.back();
				got.pop_back();
				j--;
			}
		}
	}
	std::cout << ans << "\n";
}