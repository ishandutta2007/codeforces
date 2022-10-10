#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,M;
	cin >> N >> M;
	int ans =N-N%M;
	if(ans < (N+1)/2) {cout << "-1\n"; return 0;}
	while(ans-M >= (N+1)/2) ans -=M;
	cout << ans << "\n";}