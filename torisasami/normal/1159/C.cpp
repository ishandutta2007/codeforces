#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long n, m, b[111111], g,ans=0,i,flag=0,t;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> b[i];
		ans += b[i] * m;
	}
	sort(b, b + n);
	t = b[n - 1];
	for (i = 0; i < m; i++) {
		cin >> g;
		if (g == t)
			flag++;
		else if (g < t)
			flag = -100000000;
		ans += g;
	}
	ans -= t * m;
	if (flag == 0)
		ans += t-b[n-2];
	if (flag < 0)
		ans = -1;
	cout << ans << endl;
}