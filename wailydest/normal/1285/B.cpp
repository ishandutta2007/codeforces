#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int n, arr[100001];
	long long sum, sumsegment;
	bool out;
	while (t--) {
		out = false;
		sum = 0, sumsegment = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		for (int i = 0; i < n - 1; ++i) {
			sumsegment += arr[i];
			if (sumsegment >= sum) {
				cout << "NO\n";
				out = true;
				break;
			}
			if (sumsegment < 0) {
				sumsegment = 0;
			}
			//cout << sum << ' ' << sumsegment << '\n';
		}
		sumsegment = 0;
		if (!out) {
			for (int i = n - 1; i > 0; --i) {
				sumsegment += arr[i];
				if (sumsegment >= sum) {
					cout << "NO\n";
					out = true;
					break;
				}
				if (sumsegment < 0) {
					sumsegment = 0;
				}
			}
			//cout << sum << ' ' << sumsegment << '\n';
		}
		if (!out) cout << "YES\n";
	}
	return 0;
}