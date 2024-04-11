#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< pair<int, int> > Ds(N);
	for(int i = 0; i < N; i++) {
		cin >> Ds[i].ff;
		Ds[i].ss = i;
	}
	sort(begin(Ds), end(Ds));
	reverse(begin(Ds), end(Ds));
	vector< pair<int, int> > ans;
	vector<int> seq(1, 2*Ds[0].ss);
	for(int i = 1; i < N; i++) {
		seq.push_back(2*Ds[i].ss);
		ans.push_back({2*Ds[i].ss+1, 2*Ds[i-1].ss+1});
	}
	for(int i = 0; i < N; i++) {
		int d = Ds[i].ff-1;
		int id = 2*Ds[i].ss+1;
		ans.push_back({seq[i+d]+1, id+1});
		if(i+d == (int)seq.size()-1) seq.push_back(id);
	}
	for(auto & p : ans) cout << p.ff << " " << p.ss << "\n";
}