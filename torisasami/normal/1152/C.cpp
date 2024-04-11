#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long a, b, d, i,  t = 0,p[22222222],ca,cb,k,s,min=0,ans;
	cin >> a >> b;
	long keep;
	if (a > b) {
		keep = a;
		a = b;
		b = keep;
	}
	d = b-a;
	for (i = 1; i*i <= d; i++) {
		if (d%i == 0) {
			p[t] = i;
			t++;
			if (i*i != d) {
				p[t] = d / i;
				t++;
			}
		}
	}
	for (i = 0; i < t; i++) {
		k = p[i] - a % p[i];
		if (a%p[i] == 0)
			k = 0;
		ca = a + k;
		cb = b + k;
		s = ca * cb / p[i];
		if (min==0||s < min) {
			min = s;
			ans = k;
		}
	}
	cout << ans << endl;
}