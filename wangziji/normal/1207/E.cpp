#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	cout << "? ";
	for(int i=1;i<=101;i++)
	{
		if(i!=64)
			cout << i << " ";
	}
	cout << endl;
	int l;
	cin >> l;
	cout << "? ";
	for(int i=2;i<=101;i++)
		cout << i*128 << " ";
	cout << endl;
	int r;
	cin >> r;
	cout << "! " << l/128*128+r%128 << endl;
	return 0;
}