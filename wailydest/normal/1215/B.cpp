#include <iostream>
#include <utility>
using namespace std;

int main() 
{
	pair<long long, long long> prev = make_pair(0, 0), sum = make_pair(0, 0);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		++prev.first;
		if (x < 0) {
			swap(prev.first, prev.second);
		}
		sum.first += prev.first;
		sum.second += prev.second;
	}
	cout << sum.second << ' ' << sum.first << '\n';
	return 0;
}