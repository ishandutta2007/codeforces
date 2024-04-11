#include <bits/stdc++.h>
using namespace std;

string a;
int main(void) {
	int n , ans = 0;
	cin >> a;
	n = a.length();
	for(int i = 0;i < n;++ i) {
		if(isdigit(a[i])) {
			if((a[i] - '0') & 1) ans ++;
		}
		else if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] =='o' || a[i] == 'u') ans ++;
	}
	cout << ans;
}