#include <iostream>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int d;
		cin >> d;
		double a, b;
		if(d==0) a = b = 0;
		else if(d<4) {
			cout << "N\n";
			continue;
		}
		else {
			a = (d+sqrt(d*d-4*d))/2; b = a/(a-1);
		}
		cout << fixed << setprecision(9) << "Y " << a << " " << b << endl;
	}
}