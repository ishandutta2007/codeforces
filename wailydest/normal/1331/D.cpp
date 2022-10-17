#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string str;
	cin >> str;
	cout << ((int)(*(str.end() - 1) - '0') & 1) << '\n';
	return 0;
}