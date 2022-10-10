#include <iostream>
#include <vector>
#include <algorithm>
#define ff first
#define ss second
using namespace std;

using cat = long long;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< pair<cat, int> > VA[2];
	for(int i = 2; i < N; i++) {
		int sgn;
		cat A;
		cout << "1 1 2 " << i+1 << endl;
		cin >> A;
		cout << "2 1 2 " << i+1 << endl;
		cin >> sgn;
		VA[(sgn < 0) ? 0 : 1].push_back({A, i});
	}
	vector<int> P;
	for(int k = 0; k < 2; k++) {
		if(VA[k].empty()) {
			P.push_back(k);
			continue;
		}
		sort(begin(VA[k]), end(VA[k]));
		vector< pair<cat, int> > OA[2];
		for(int i = 0; i < (int)VA[k].size()-1; i++) {
			cout << "2 " << k+1 << " " << VA[k][i].ss+1 << " " << VA[k].back().ss+1 << endl;
			int sgn;
			cin >> sgn;
			if(sgn == 1) OA[0].push_back(VA[k][i]);
			else OA[1].push_back(VA[k][i]);
		}
		reverse(begin(OA[1]), end(OA[1]));
		P.push_back(k);
		for(auto p : OA[0]) P.push_back(p.ss);
		P.push_back(VA[k].back().ss);
		for(auto p : OA[1]) P.push_back(p.ss);
	}
	cout << "0";
	for(int i = 0; i < N; i++) cout << " " << P[i]+1;
	cout << endl;
}