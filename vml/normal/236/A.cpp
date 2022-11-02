#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <set>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set <char> count;
	string name;
	cin>> name;
	for(int i = 0; i < (int)name.size(); i++)
	{
		count.insert(name[i]);
	}
	if(count.size() % 2 == 0)
	{
		printf("CHAT WITH HER!");
	}
	else
	{
		printf("IGNORE HIM!");
	}
	return 0;
}