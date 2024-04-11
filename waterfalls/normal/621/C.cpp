#include <bits/stdc++.h>
using namespace std;

int n,p,l,r;
double num[100013];

int main() {
	cin >> n >> p;
	for (int i=0;i<n;i++) {
		cin >> l >> r;
		num[i] = 1-1.*(r/p-(l-1)/p)/(r-l+1);
	}
	double ans = 0;
	for (int i=0;i<n;i++) ans+=1-num[i]*num[(i+1)%n];
	cout << fixed << setprecision(12) << (ans*2000);
}