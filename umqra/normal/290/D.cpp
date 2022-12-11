#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int n;
	cin >> str >> n;
	for (int i = 0; i < (int)str.length(); i++)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	for (int i = 0; i < (int)str.length(); i++)
	{
		int c = str[i];                	
		if (c < n + 97)
			str[i] = str[i] - 'a' + 'A';
	}
	cout << str;
	return 0;
}