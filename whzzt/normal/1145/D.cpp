#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, a[N], w;
int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	w = a[n];
	for (int i = 1; i <= n; ++i) w = min(w, a[i]);
	w ^= a[3];
	cout << 2 + w << endl;
}