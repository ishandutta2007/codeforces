#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	if(n<2)
	{
		puts("-1");
		return 0;
	}
	cout << n << " " << n;
	return 0;
}