#include <bits/stdc++.h>
using namespace std;

const int primes[]={2, 3, 5, 7, 11};
int n;
vector<int> ans={1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; ; ++i) {
		for(int j=0; j<ans.size(); ++j)
			if(ans[j]*primes[i]<=2*n*n)
				ans.push_back(ans[j]*primes[i]);
		if(ans.size()>=n)
			break;
	}
	for(int i=0; i<n; ++i)
		cout << ans[ans.size()-i-1] << " ";
}