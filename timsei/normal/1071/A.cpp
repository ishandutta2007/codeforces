#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long
int a, b;

bool vis[N];

main() {
	cin >> a >> b;
	int ans = (a + b);
	int res = 0;
	for(int i = 1; ; ++ i) {
		res += i;
		if(res > ans) {
			res = i - 1; break;
		}
	}
	int now = (res + 1) * res / 2;
	if(a > now) {
		a = now, b = 0;
	}
	else b = now - a;
	int n = res, T = 0;
	vector <int> A;
	A.clear();
	for(int i = n; i >= 1; -- i) {
		if(T + i <= a) {
			A.push_back(i);
			T += i;
		}
		else {
			if(a - T) A.push_back(a - T);
			break;
		}
	}
	cout << A.size() << endl;
	for(int i = 0; i < (int) A.size(); ++ i) printf("%d ", A[i]), vis[A[i]] = 1;
	puts("");
	cout << n - A.size() << endl;
	for(int i = 1; i <= n; ++ i) if(!vis[i]) printf("%d ", i);
}