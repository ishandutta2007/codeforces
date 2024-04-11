#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

string read()
{

	string s, p;
	cin >> s >> p;
	reverse(p.begin(), p.end());
	s += p;
	string ans = "";
	int x = 0;
	while(s[x] != 'A') x++;
	for (int i = x; i < 4; i++)
		if (s[i] != 'X')
			ans.push_back(s[i]);
	for (int i = 0; i < x; i++)
		if (s[i] != 'X')
			ans.push_back(s[i]);
//	cout << ans << endl;
	return ans;
}

int main()
{
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string s = read();
	string p = read();

	if (s == p)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}