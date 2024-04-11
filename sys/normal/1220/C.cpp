#include <bits/stdc++.h>
using namespace std;
int mini = 0x3f3f3f3f;
string str;
int main()
{
	cin >> str;
	int siz = str.size();
	for (int i = 0; i < siz; i++)
	{
		if (str[i] - 'a' <= mini)
			printf("Mike\n"), mini = str[i] - 'a';
		else printf("Ann\n");
	}
	return 0;
}