#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, m, a;
	cin >> n >> m;
	a=n;
	while(m>(n-a)*(n-a-1)/2)
		--a;
	cout << max(n-2*m, 0ll) << " " << a;
}