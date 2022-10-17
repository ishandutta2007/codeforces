#include <iostream>
#include <set>
using namespace std;

bool solve() 
{
	int n;
	cin >> n;
	
	set<int> s;
	
	int arr[5000];
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	s.insert(arr[0]);
	s.insert(arr[1]);
	for (int i = 2; i < n; ++i) {
		if (s.count(arr[i]) && (arr[i] != arr[i - 1] || arr[i] == arr[i - 2])) return true;
		s.insert(arr[i]);
	}
	return false;
}

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