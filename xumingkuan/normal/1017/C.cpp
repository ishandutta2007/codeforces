#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	int x = 1;
	while(x * x < n)
		x++;
	int y = x;
	if((x - 1) * x >= n)
		y--;
	for(int i = 1; i <= y; i++)
		for(int j = 1; j <= x; j++)
		{
			int tmp = n - x * i + j;
			if(tmp >= 1)
				printf("%d ", tmp);
		}
	return 0;
}