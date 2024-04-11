#include <iostream>
#include <tuple>
#include <utility>
#include <cmath>
using namespace std;

class three {
public:
	int first, second, third;
};

three make_triple(int a, int b, int c) 
{
	three triple;
	triple.first = a;
	triple.second = b;
	triple.third = c;
	return triple;
}
int rounded_division(int a, int b) 
{
	if (a % b <= b / 2) return a / b;
	return a / b + 1;
}

int main() 
{
	int t;
	cin >> t;
	
	pair<three, int> option;
	
	int a, b, c, total;
	while (t--) {
		cin >> a >> b >> c;
		option = make_pair(make_triple(1, 1, 1), a + b + c - 3);
		for (int a1 = 1; a1 < 2 * a; ++a1) {
			for (int b1 = a1; b1 < 2 * b; b1 += a1) {
				int c1 = (rounded_division(c, b1) * b1);
				//cout << '$' << a1 << ' ' << b1 << ' ' << c1 << '\n';
				if (option.second > abs(a - a1) + abs(b - b1) + abs(c - c1)) option = make_pair(make_triple(a1, b1, c1), abs(a - a1) + abs(b - b1) + abs(c - c1));
			}
		}
		cout << option.second << '\n' << option.first.first << ' ' << option.first.second << ' ' << option.first.third << '\n';
	}
	return 0;
}