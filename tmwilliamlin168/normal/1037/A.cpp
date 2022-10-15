#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a=0;
	cin >> n;
	while(n) {
		++a;
		n/=2;
	}
	cout << a;
}