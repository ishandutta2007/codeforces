#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	long long a,b,c;
	cin >> a >> b >> c;
	cout << c*2+min(a,b)*2-(a==b)+1;
	return 0;
}