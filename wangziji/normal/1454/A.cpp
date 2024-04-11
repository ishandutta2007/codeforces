#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x;
		for(int i=1;i<x;i++) cout << i+1 << " ";
		puts("1");
	}
	return 0;
}