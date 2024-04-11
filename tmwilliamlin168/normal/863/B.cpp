#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> w;
	for(int i=0; i<2*n; ++i) {
		int wi;
		cin >> wi;
		w.push_back(wi);
	}
	sort(w.begin(), w.end());
	int _min=INT_MAX;
	for(int i=0; i<2*n; ++i) {
		for(int j=i+1; j<2*n; ++j) {
			int c=0, k=0;
			for(int l=0; l<n-1; ++l) {
				if(k==i) ++k;
				if(k==j) ++k;
				c-=w[k];
				++k;
				if(k==i) ++k;
				if(k==j) ++k;
				c+=w[k];
				++k;
			}
			_min=min(c, _min);
		}
	}
	cout << _min;
}