#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, a[mxN], mn=-1, cn;
vector<int> zs;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(a[i]<0) {
			++cn;
			if(mn==-1||a[mn]<a[i])
				mn=i;
		} else if(!a[i])
			zs.push_back(i);
	}
	if(cn&1)
		zs.push_back(mn);
	if(zs.size()) {
		for(int i=0; i<zs.size()-1; ++i)
			cout << "1 " << zs[i]+1 << " " << zs[i+1]+1 << "\n";
		if(zs.size()<n)
			cout << "2 " << zs.back()+1 << "\n";
	}
	for(int i=0, l=-1; i<n; ++i) {
		if(!a[i]||(i==mn&&cn&1))
			continue;
		if(l!=-1)
			cout << "1 " << l+1 << " " << i+1 << "\n";
		l=i;
	}
}