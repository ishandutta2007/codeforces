#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n<4)
			cout << 4-n << endl;
		else
		{
			cout << n%2 << endl;
		}
	}
	return 0;
}