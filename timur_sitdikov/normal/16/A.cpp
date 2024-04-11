#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char c[105][105];

int main()
{	

	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
		scanf("%s", &c[i]);
	for(i=0; i<n; i++)
		for(j=1; j<m; j++)
			if (c[i][j]!=c[i][j-1])
			{printf("NO"); return 0;}
	for(i=1; i<n; i++)
		if (c[i][0]==c[i-1][0])
			{printf("NO"); return 0;}
		printf("YES");
}