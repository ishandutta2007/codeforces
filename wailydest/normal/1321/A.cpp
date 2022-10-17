#include <iostream>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	bool r[100], b[100];
	for (int i = 0; i < n; ++i) cin >> r[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	int only_r = 0, only_b = 0, common = 0;
	for (int i = 0; i < n; ++i) {
		if (r[i] && b[i]);
		else if (r[i]) ++only_r;
		else if (b[i]) ++only_b;
	}
	int maxi = 0;
	if (only_r) cout << only_b / only_r + 1;
	else cout << -1;
	cout << '\n';
	
	return 0;
}