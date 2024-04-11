#include <bits/stdc++.h>
using namespace std;
int h, m, s, t1, t2;
double T1, T2, a[4];
const double eps = 1e-8;
int dcmp(double x) {
	return (x > eps) - (x < -eps);
}
bool in(double a, double b, double c) {
	return dcmp(c - a) >= 0 && dcmp(c - b) <= 0;
}
int main() {
	//freopen("B.in","r",stdin);
	scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
	a[0] = (h + (m * 60 + s) / 3600.0) / 12.0;
	a[1] = (m + s / 60.0) / 60.0;
	a[2] = s / 60.0;
	sort(a, a + 3);
	a[3] = a[0] + 1;
	
	T1 = t1 / 12.0;
	T2 = t2 / 12.0;
	//cout << T1 << " " << T2 << endl;
	bool flag = false;
	for (int i = 0; i < 3; ++i) {
		if (in(a[i], a[i + 1], T1) && in(a[i], a[i + 1], T2)) flag = true;
	}
	if (T1 < T2) swap(T1, T2);
	if (in(a[2], a[3], T1) && in(a[2], a[3], T2 + 1)) flag = true;
	if (in(a[2], a[3], T1 + 1) && in(a[2], a[3], T2 + 1)) flag = true;
	puts(flag ? "YES" : "NO"); 
}