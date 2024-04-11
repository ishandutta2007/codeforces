#include <iostream>
using namespace std;

int single(int h, int m) {
	return 1440 - h * 60 - m;
}

int main() 
{
	int amount, h, m;
	cin >> amount;
	for (int i = 0; i < amount; ++i) {
		cin >> h >> m;
		cout << single(h, m) << '\n';
	}
}