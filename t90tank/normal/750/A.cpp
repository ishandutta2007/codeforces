#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back

int main() {
	int n, k; 
	cin>>n>>k; 
	for (int i = 1; i <= n+1; ++i) {
		if (k + 5*i > 240 || i == n+1) {
			cout<<i-1<<endl; 
			break; 
		}
		else k += 5*i; 
	}
}