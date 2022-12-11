#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < (int)a.length(); i++)
		if (a[i] == '1')
			cnt1++;

	for (int i =0 ; i < (int)b.length(); i++)
		if (b[i] == '1')
			cnt2++;

	if (cnt1 % 2 == 1)
		cnt1++;

	if (cnt1 >= cnt2)	
		puts("YES");
	else
		puts("NO");

	return 0;
}