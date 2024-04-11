#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int k;
	string s;

	cin >> k;
	cin >> s;

	static int sum[26];
	for (string::iterator i = s.begin(); i != s.end(); i++)
		sum[*i - 'a']++;
	for (int i = 0; i < 26; i++)
		if (sum[i] % k != 0)
		{
			cout << -1 << endl;
			return 0;
		}
	for (int i = 0; i < 26; i++)
		sum[i] /= k;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < 26; j++)
			for (int k = 0; k < sum[j]; k++)
				cout << (char)('a' + j);
	cout << endl;

	return 0;
}