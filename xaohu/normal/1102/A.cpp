#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << (n % 4 == 1 || n % 4 == 2) << endl;
	return 0;
}