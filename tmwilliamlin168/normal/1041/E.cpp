#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
int n, ai, bi, c[1000];
vector<int> a1[1000];

void fk() {
	cout << "NO";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1; i<n; ++i) {
		cin >> ai >> bi;
		if(bi!=n)
			fk();
		++c[ai];
	}
	for(int i=1; i<n; ++i)
		if(c[i])
			a1[i].push_back(i);
	for(int i=1, j=1; i<n; ++i) {
		if(c[i])
			continue;
		while(a1[j].size()>=c[j])
			++j;
		if(j<i)
			fk();
		a1[j].push_back(i);
	}
	cout << "YES\n";
	for(int i=1; i<n; ++i) {
		if(!c[i])
			continue;
		a1[i].push_back(n);
		for(int j=0; j<a1[i].size()-1; ++j)
			cout << a1[i][j] << " " << a1[i][j+1] << "\n";
	}
}