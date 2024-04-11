#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;

int a[mxN], t[mxN], p[mxN];
vector<int> byA[mxN+1];

struct cmp {
	bool operator()(const int &x, const int &y) const {
		return t[x]==t[y]?x<y:t[x]<t[y];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> a[i] >> t[i];
		p[i]=i;
		byA[a[i]].push_back(i);
	}
	sort(p, p+n, cmp());
	set<int, cmp> s;
	int maxT=0;
	for(int i=0, c=0, used=0; i<n; ++i) {
		if(a[p[i]]<=maxT)
			continue;
		if(c+1>maxT) {
			for(int j : byA[maxT]) {
				if(s.erase(j)) {
					used-=t[j];
					--c;
				}
			}
		}
		if(used+t[p[i]]<=m) {
			s.insert(p[i]);
			used+=t[p[i]];
			++c;
		}
		maxT=max(c, maxT);
	}
	cout << maxT << "\n" << maxT << "\n";
	for(int i1=0, i2=0; i2<maxT; ++i1) {
		if(a[p[i1]]>=maxT) {
			cout << p[i1]+1 << " ";
			++i2;
		}
	}
}