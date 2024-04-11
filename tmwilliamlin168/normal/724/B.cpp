#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, **mat;

bool testPerm(int* perm) {
	for(int i=0; i<n; ++i) {
		int displaced=0;
		for(int j=0; j<m; ++j)
			if(mat[i][j]!=perm[j])
				++displaced;
		//cout << displaced << endl;
		if(displaced>2)
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	mat = new int*[n];
	for(int i=0; i<n; ++i)
		mat[i] = new int[m];
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> mat[i][j];

	int* perm = new int[m];
	for(int i=0; i<m; ++i)
		perm[i]=i+1;
	if(testPerm(perm)) {
		cout << "YES";
		return 0;
	}
	for(int i=0; i<m; ++i) {
		for(int j=i+1; j<m; ++j) {
			perm[i]^=perm[j];
			perm[j]^=perm[i];
			perm[i]^=perm[j];
			if(testPerm(perm)) {
				cout << "YES";
				return 0;
			}
			perm[i]^=perm[j];
			perm[j]^=perm[i];
			perm[i]^=perm[j];
		}
	}
	cout << "NO";
	return 0;
}