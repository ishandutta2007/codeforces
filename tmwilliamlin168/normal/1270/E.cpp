#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n;
ll x[mxN], y[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<int> a;
	while(1) {
		a.clear();
		for(int i=0; i<n; ++i) {
			if((x[i]+y[i])&1)
				a.push_back(i);
		}
		if(a.size()==0||a.size()==n) {
			for(int i=0; i<n; ++i) {
				if((x[i]+y[i])&1)
					++y[i];
				ll x2=(x[i]+y[i])/2, y2=(x[i]-y[i])/2;
				x[i]=x2;
				y[i]=y2;
			}
		} else
			break;
	}
	cout << a.size() << "\n";
	for(int ai : a)
		cout << ai+1 << " ";
}