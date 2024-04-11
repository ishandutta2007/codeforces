#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int x, y, a, b;
	scanf("%d %d %d %d", &x, &y, &a, &b);
	bool first = true;
	int numb = 0;
	for(int i = a; i <= x; i++)
	{
		for(int j = b; j < min(y + 1, i); j++)
		{
			numb++;
		}
	}
	printf("%d\n", numb);
	for(int i = a; i <= x; i++)
	{
		for(int j = b; j < min(y + 1, i); j++)
		{
			if(first)
			{
				first = false;
			}
			else
			{
				printf("\n");
			}
			printf("%d %d", i, j);
		}
	}
	return 0;
}