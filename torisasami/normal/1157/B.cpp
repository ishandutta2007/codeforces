#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, i, f[11];
	char s[222222];
	cin >> n >> s;
	for (i = 1; i <= 9; i++)
		cin >> f[i];
	int flag = 0;
	for (i = 0; i < n; i++) {
		int p = s[i] - '0';
		if (flag == 0) {
			if (p < f[p]) {
				flag++;
				s[i] = f[p] + '0';
			}
		}
		else if (flag == 1) {
			if (p > f[p])
				flag *= -1;
			else
				s[i] = f[p] + '0';
		}
	}
	cout << s << endl;
}