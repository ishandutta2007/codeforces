#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, f[mxN];
bool vis[mxN], a[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> b, c1, c2;
	for(int i=0; i<n; ++i) {
		cin >> f[i], --f[i];
		if(~f[i])
			a[f[i]]=1;
	}
	for(int i=0; i<n; ++i) {
		if(f[i]<0)
			b.push_back(i);
		if(!a[i]) {
			if(~f[i])
				c1.push_back(i);
			else
				c2.push_back(i);
		}
	}
	for(int bi : b) {
		if(a[bi]) {
			if(c2.size()) {
				f[bi]=c2.back();
				c2.pop_back();
			} else {
				f[bi]=c1.back();
				c1.pop_back();
			}
		}
	}
	for(int bi : b) {
		if(f[bi]<0) {
			bool k=c2.size()&&c2.back()==bi;
			if(k)
				c2.pop_back();
			if(c2.size()) {
				f[bi]=c2.back();
				c2.pop_back();
			} else {
				f[bi]=c1.back();
				c1.pop_back();
			}
			if(k)
				c2.push_back(bi);
		}
	}
	for(int i=0; i<n; ++i)
		cout << f[i]+1 << " ";
}