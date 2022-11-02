#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int ans = 1, n;
	string last, tmp;
	cin >> n;
	cin >> last;
	while (--n) {
		cin >> tmp;
		if (last != tmp) {
			++ans;
		}
		last = tmp;
	}
	cout << ans << endl;
	return 0;
}