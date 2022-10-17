#include <iostream>
#include <set>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	multiset<int> divisors;
	int val;
	while (n--) {
		cin >> val;
		divisors.insert(val);
	}
	
	int max = *prev(divisors.end());
	
	cout << max << ' ';
	
	for (int i = 2; i <= max; ++i) {
		if (!(max % i)) divisors.erase(divisors.find(i));
	}
	
	cout << *prev(divisors.end()) << '\n';
	
	return 0;
}