#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, mxA=2750131;
int n, b[2*mxN], p[mxA+1], lpf[mxA+1];
vector<int> ps, a;
multiset<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i=2, j=1; i<=mxA; ++i) {
		if(!lpf[i]) {
			p[i]=j++;
			lpf[i]=i;
			ps.push_back(i);
		}
		for(int k=0; k<ps.size()&&ps[k]<=lpf[i]&&i*ps[k]<=mxA; ++k)
			lpf[i*ps[k]]=ps[k];
	}

	cin >> n;
	for(int i=0; i<2*n; ++i) {
		cin >> b[i];
		s.insert(b[i]);
	}
	while(!s.empty()) {
		auto it=--s.end();
		//cout << "hi1 " << (*it) << endl;
		//cout << p[5] << endl;
		if(p[*it]) {
			a.push_back(p[*it]);
			s.erase(s.find(p[*it]));
		} else {
			a.push_back(*it);
			s.erase(s.find((*it)/lpf[*it]));
		}
		s.erase(it);
	}
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
}