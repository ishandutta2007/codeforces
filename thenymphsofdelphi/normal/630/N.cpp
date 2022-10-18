#include<bits/stdc++.h>
using namespace std;

int main(){
	long double a, b, c, d, x1, x2;
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	x1 = (-b + sqrt(d)) / (2 * a);
	x2 = (-b - sqrt(d)) / (2 * a);
	cout << fixed << setprecision(6) << max(x1, x2) << endl << min(x1, x2);
}