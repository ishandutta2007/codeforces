#include <iostream>
#include <utility>
#include <set>
using namespace std;

bool solve();
int find_max(int *arr, int n);

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		if (solve()) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
	return 0;
}

bool solve() 
{
	int arr[100];
	set<int> p;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	int val;
	while (m--) {
		cin >> val;
		p.insert(val);
	}
	
	int max_index;
	for (int length = n; length > 1; --length) {
		max_index = find_max(arr, length);
		if (max_index != length - 1) {
			do {
				//cout << '$' << max_index << ' ' << arr[max_index] << '\n';
				if (p.count(max_index + 1)) {
					swap(arr[max_index], arr[max_index + 1]);
					++max_index;
				}
				else return 0;
			} while (max_index != length - 1);
		}
	}
	return 1;
}

int find_max(int *arr, int n) 
{
	int max_index = 0, max = arr[0];
	for (int i = 1; i < n; ++i) {
		if (max <= arr[i]) {
			max = arr[i];
			max_index = i;
		}
	}
	return max_index;
}