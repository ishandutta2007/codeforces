#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, i, l, r, a[222222],min,ans=0,now=0,p;
	char s[222222];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < 222222; i++)
		s[i] = '\0';
	l = 0;
	r = n - 1;
	while (1) {
		min = 1111111;
		p = -1;
		if (a[l] > now) {
			if (a[l] < min) {
				min = a[l];
				p = 0;
			}
		}
		if (a[r] > now) {
			if (a[r] < min) {
				min = a[r];
				p = 1;
			}
		}
		if (p < 0||ans==n)
			break;
		if (a[l] == a[r]) {
			int lm = 1, rm = 1;
			i = l + 1;
			while (a[i] > a[i - 1]) {
				lm++;
				i++;
			}
			i = r - 1;
			while (a[i] > a[i + 1]) {
				rm++;
				i--;
			}
			if (lm > rm) {
				for (i = 0; i < lm; i++) {
					s[ans] = 'L';
					ans++;
				}
			}
			else {
				for (i = 0; i < rm; i++) {
					s[ans] = 'R';
					ans++;
				}
			}
			break;
		}
		else if (p == 0) {
			now = a[l];
			l++;
			s[ans] = 'L';
		}
		else {
			now = a[r];
			r--;
			s[ans] = 'R';
		}
		ans++;
	}
	cout << ans << endl << s << endl;
}