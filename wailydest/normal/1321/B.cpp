#include <iostream>
#include <map>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	int arr[200000];
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	map<int, long long> ways;
	for (int i = 0; i < n; ++i) ways[arr[i] - i] += arr[i];
	
	long long max_ways = 0;
	for (auto const& [key, val] : ways) if (max_ways < val) max_ways = val;
	
	cout << max_ways << '\n';
	
	return 0;
}