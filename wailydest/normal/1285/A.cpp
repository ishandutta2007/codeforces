#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int min_pos = 0, max_pos = 0;
	char cmd;
	while (t--) {
		cin >> cmd;
		if (cmd == 'L') --min_pos;
		else ++max_pos;
	}
	cout << max_pos - min_pos + 1;
	return 0;
}