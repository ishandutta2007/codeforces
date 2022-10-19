#include <bits/stdc++.h>
using namespace std;

main(void) {
	int n;
	cin >> n;
	int now = (int) sqrt(n);
	if(n % now != 0) {
		vector <int> cxt;
		cxt.clear();
		for(int i = 1; i <= n % now; ++ i) cxt.push_back(i);
		for(int i = cxt.size() - 1; i >= 0; -- i) cout << cxt[i] <<" ";
	}
	for(int i = n % now + 1; i <= n; i += now) {
		for(int j = i + now - 1; j >= i; -- j) printf("%d ", j);
	}
}