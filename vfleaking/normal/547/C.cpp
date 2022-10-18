#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 200000;
const int MaxNP = 6; 

int main() {
	int n, nQ;
	static vector<int> fp[MaxN + 1];
	static vector<int> fd[MaxN + 1];
	map<int, int> ma;
	static pair<int, int> f[MaxN * (1 << MaxNP)];
	
	cin >> n >> nQ;
	for (int i = 1; i <= n; i++) {
		int ai;
		scanf("%d", &ai);
		
		for (int t = 2; t * t <= ai; t++) {
			if (ai % t == 0) {
				while (ai % t == 0) {
					ai /= t;
				}
				fp[i].push_back(t);
			}
		}
		if (ai > 1) {
			fp[i].push_back(ai);
		}
		
		int fpn = (int)fp[i].size();
		
		for (int s = 0; s < (1 << fpn); s++) {
			int c = 1;
			int prod = 1;
			for (int k = 0; k < fpn; k++) {
				if (s >> k & 1) {
					c *= -1;
					prod *= fp[i][k];
				}
			}
			if (!ma.count(prod)) {
				int lab = (int)ma.size();
				ma[prod] = lab;
				f[lab].second = c;
			}
			fd[i].push_back(ma[prod]);
		}
	}
	
	static bool has[MaxN + 1];
	
	int nOne = 0;
	
	long long res = 0;
	while (nQ--) {
		int p;
		scanf("%d", &p);
		
		int c;
		
		if (has[p]) {
			c = -1;
			has[p] = false;
		} else {
			c = 1;
			has[p] = true;
		}
		
		if (fp[p].empty()) {
			nOne += c;
		}
		
		for (int k = 0; k < (int)fd[p].size(); k++) {
			pair<int, int> &ret = f[fd[p][k]];
			res -= (long long)ret.first * ret.first * ret.second;
			ret.first += c;
			res += (long long)ret.first * ret.first * ret.second;
		}
		
		cout << (res - nOne) / 2 << endl;
	}
	
	return 0;
}