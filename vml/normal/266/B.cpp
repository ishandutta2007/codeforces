#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	string s;
	cin >> s;
	for(int j = 1; j <= t; j++)
	{
		for(int i = 0; i < (int) s.size() - 1; i++)
		{
			if(s[i] == 'B' && s[i + 1] == 'G')
			{
				swap(s[i], s[i + 1]);
				i++;
			}
		}
	}
	cout << s;
	return 0;
}