#include<iostream>
using namespace std;
int main() {
	int n, i;
	char s[333333];
	cin >> n >> s;
	int count = 0;
	for (i = 0; i <= n - 11; i++) {
		if (s[i] == '8')
			count++;
	}
	if (count > (n - 11) / 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}