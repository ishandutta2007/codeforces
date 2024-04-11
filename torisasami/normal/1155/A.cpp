#include<iostream>
using namespace std;
int main() {
	int n, i;
	char s[333333];
	scanf("%d%*c%s", &n, s);
	for (i = 1; i < n; i++) {
		if (s[i - 1] > s[i]) {
			cout << "YES" << endl << i << " " << i + 1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}