#include <iostream>
using namespace std;
int a[505][505];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	cout << n*3+4 << "\n";
	cout << "0 0\n";
	for(int i=0;i<=n;i++)
	{
		cout << i+1 << " " << i+1 << "\n";
		cout << i << " " << i+1 << "\n";
		cout << i+1 << " " << i << "\n";
	}
	return 0;
}