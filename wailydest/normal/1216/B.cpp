#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool comp (pair<int, int> a, pair<int, int> b) 
{
	return a.first > b.first;
}

int main() 
{
	int n;
	cin >> n;
	
	vector<pair<int, int> > arr(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	
	sort(arr.begin(), arr.end(), comp);
	
	long long result = 0;
	for (int i = 0; i < n; ++i) {
		result += arr[i].first * i + 1;
	}
	
	cout << result << '\n';
	for (int i = 0; i < n; ++i) cout << arr[i].second << ' ';
	cout << '\n';
	
	return 0;
}