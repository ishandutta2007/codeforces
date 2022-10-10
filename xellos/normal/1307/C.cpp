#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	int N = S.length();
	vector<cat> occ(26, 0);
	vector< vector<cat> > occ2(26, vector<cat>(26, 0));
	for(int i = 0; i < N; i++) {
		int c = S[i]-'a';
		for(int j = 0; j < 26; j++) occ2[j][c] += occ[j];
		occ[c]++;
	}
	cat max_occ = 0;
	for(int i = 0; i < 26; i++) {
		max_occ = max(max_occ, occ[i]);
		for(int j = 0; j < 26; j++) max_occ = max(max_occ, occ2[i][j]);
	}
	cout << max_occ << "\n";
}