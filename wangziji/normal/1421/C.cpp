#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	string s;
	cin >> s;
	int n=s.size();
	puts("3\nL 2\nR 2");
	cout << "R " << 2*n-1;
	return 0;
}