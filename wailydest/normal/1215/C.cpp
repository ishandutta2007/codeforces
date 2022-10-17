#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() 
{
	int n;
	string s, t;
	vector<int> toswap1, toswap2;
	
	cin >> n >> s >> t;
	
	for (int i = 0; i < n; ++i) 
	{
		if (s[i] == 'a' && t[i] == 'b') toswap1.push_back(i);
		else if (s[i] != t[i]) toswap2.push_back(i);
	}
	
	if ((toswap1.size() + toswap2.size()) & 1) {
		cout << -1 << '\n';
		return 0;
	}
	
	cout << toswap1.size() / 2 + toswap2.size() / 2 + (toswap1.size() & 1) * 2 << '\n';
	
	for (vector<int>::iterator it = toswap1.begin() + 1; it < toswap1.end(); it += 2) {
		cout << *it + 1 << ' ' << *(it - 1) + 1 << '\n';
	}
	for (vector<int>::iterator it = toswap2.begin() + 1; it < toswap2.end(); it += 2) {
		cout << *it + 1 << ' ' << *(it - 1) + 1 << '\n';
	}
	
	if (toswap1.size() & 1) {
		cout << *(toswap1.end() - 1) + 1 << ' ' << *(toswap1.end() - 1) + 1 << '\n';
		cout << *(toswap1.end() - 1) + 1 << ' ' << *(toswap2.end() - 1) + 1 << '\n';
	}
	
	return 0;
}