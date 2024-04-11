#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m, y, tot, L[N], R[N], opt[N], W[N], ok[N], w;
bitset <N> who[N];

map < string, int> Map;

char s[N];

bool get(int x, int bit) {
	return W[x];
}

bool perf(int x, int bit) {
	if(!opt[x]) {
		return W[x] = who[x][bit];
	}
	if(opt[x] == 1) return W[x] = (get(L[x], bit) & get(R[x], bit));
	else if(opt[x] == 2) return W[x] = (get(L[x], bit) || get(R[x], bit));
	else return W[x] = (get(L[x], bit) ^ get(R[x], bit));
}

vector < int > A, B;

int main() {
	cin >> n >> m;
	Map["?"] = 1;
	++ tot;
	for(int i = 1; i <= n; ++ i) {
		string s;
		cin >> s;
		Map[s] = ++ tot;
		cin >> s;
		cin >> s;
		if(isdigit(s[0])) {
			opt[tot] = 0;
			for(int j = 0; j < (int) s.size(); ++ j) who[tot][j] = s[j] - '0';
			continue;
		}
		L[tot] = Map[s];
		cin >> s;
		if(s == "AND") opt[tot] = 1;
		else if(s == "OR") opt[tot] = 2;
		else if(s == "XOR") opt[tot] = 3;
		cin >> s;
		R[tot] = Map[s]; 
	}
	for(int i = 0; i < m; ++ i) {
		W[1] = 0;
		int l = 0, r = 0;
		for(int j = 2; j <= tot; ++ j) {
			l += perf(j, i);
		}
		W[1] = 1;
		for(int j = 2; j <= tot; ++ j) {
			r += perf(j, i);
		}
		if(l == r) A.push_back(0), B.push_back(0);
		else {
			if(l < r) A.push_back(0), B.push_back(1);
			else A.push_back(1), B.push_back(0);
		}
	}
	for(int i = 0; i < m; ++ i) putchar(A[i] + '0');
	puts("");
	for(int i = 0; i < m; ++ i) putchar(B[i] + '0');
	puts("");
}