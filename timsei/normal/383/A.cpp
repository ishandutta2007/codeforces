#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1111111;

int A[N] , n , m , x , y , ans , nowres , S[N] , S2[N];

main(void) {
	cin >> n;
	for(int i = 1;i <= n;++ i) {
		cin >> A[i];
		if(A[i] == 1) {
			++ S[A[i]]; -- S[n + 1]; S2[i] = n - i;
		}
		else ++ S[1] , -- S[A[i] + 1] , S2[i] = i - 1;
	}
	for(int i = 1;i <= n;++ i) S[i] += S[i - 1];
	ans = 2e9;
	nowres = 0;
	int tot = 0;
	for(int i = 1;i <= n;++ i) {
		if(A[i] == 0) {
			nowres += tot;
		}
		else ++ tot;
	}
	ans = min(ans , nowres);
	cout << nowres;
}