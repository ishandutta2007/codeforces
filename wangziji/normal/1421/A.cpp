#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> a >> b;
		cout << (a^b) << "\n";
	}
	return 0;
}