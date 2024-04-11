#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, ai, _min=INT_MAX;
	cin >> n >> k;
	for(int i=0; i<n; ++i) {
		cin >> ai;
		if(k%ai==0)
			_min=min(k/ai, _min);
	}
	cout << _min;
}