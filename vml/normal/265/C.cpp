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

using namespace std;

int main()
{
	string s;
	cin >> s;
	vector <int> v(s.size());
	int left = 0, right = (int) v. size() - 1;
	for(int i = 0; i < (int)s.size(); i++)
	{
		if(s[i] == 'l')
		{
			v[right] = i + 1;
			right--;
		}
		else
		{
			v[left] = i + 1;
			left++;
		}
	}
	bool first = true;
	for(int i = 0; i < (int) v.size(); i++)
	{
		if(first)
		{
			first = false;
		}
		else
		{
			printf("\n");
		}
		printf("%d", v[i]);
	}
	return 0;
}