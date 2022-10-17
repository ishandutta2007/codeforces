#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	int arr[200000];
	
	int val;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) {
		cin >> val;
		arr[i] -= val;
	}
	
	sort(arr, arr + n);
	
	long long result = 0;
	for (int i = 1; i < n; ++i) {
		result += arr + i - upper_bound(arr, arr + i, -arr[i]);
	}
	
	cout << result << '\n';
	
	return 0;
}