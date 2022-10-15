#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
int n, a[mxN], a1, lcc=-1, r;
bool vis[mxN];
vector<int> cs[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	for(int i=0; i<n; ++i) {
		if(vis[i]||a[i]==i)
			continue;
		if(lcc==-1)
			lcc=i;
		for(int j=i; !vis[j]; cs[a1].push_back(j), vis[j]=1, j=a[j]);
		if(!a1) {
			cs[0].erase(cs[0].begin());
			cs[0].push_back(i);
		}
		++a1;
	}
	if(a1) {
		cout << n-1 << "\n";
		for(int k=0; k<a1; ++k) {
//			if(k) {
//				int b1=cs[k][0], b2=cs[k].back();
//				if(b1>b2)
//					swap(b1, b2);
//				for(int j=0; j<n; ++j)
//					cout << (j==lcc||j==b2?'/':'.');
//				cout << "\n";
//				++r;
//				for(int j=0; j<n; ++j)
//					cout << (j==lcc||j==b1||j==b2?'\\':'.');
//				cout << "\n";
//				++r;
//			}
//			if(cs[k].size()==2&&k)
//				continue;
			for(int i=0; i<cs[k].size()-1; ++i) {
				char e=cs[k][i+1]<cs[k][i]?'\\':'/';
				for(int j=0; j<n; ++j)
					cout << (j==cs[k][i+1]||j==cs[k][i]||!i&&k&&j==lcc?e:'.');
				cout << "\n";
				++r;
			}
			for(int j=0; j<n; ++j)
				cout << (j==lcc||j==cs[k].back()?'\\':'.');
			cout << "\n";
			++r;
		}
	} else
		cout << n << "\n";
	for(; r<n; ++r) {
		for(int i=0; i<n; ++i)
			cout << '.';
		cout << "\n";
	}
}