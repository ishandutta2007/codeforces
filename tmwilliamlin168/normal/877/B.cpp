#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n=s.size();
	int *pA = new int[n+1](), *pB = new int[n+1]();
	for(int i=0; i<n; ++i) {
		pA[i+1]=pA[i];
		pB[i+1]=pB[i];
		if(s[i]=='a')
			++pA[i+1];
		else
			++pB[i+1];
	}
	int _max=0;
	for(int i=0; i<n; ++i)
		for(int j=i; j<=n; ++j)
			_max=max(pA[i]-pA[0]+pB[j]-pB[i]+pA[n]-pA[j], _max);
	cout << _max;
}