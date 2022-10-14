#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
	 	double a;
	 	cin >> a;
	 	sum += a;
  }   
  cout << fixed << setprecision(12) << (double) sum / (double) n;
}