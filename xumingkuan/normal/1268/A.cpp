#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, k;
char a[202020];
void output()
{
	printf("%d\n", n);
	for(int i = 1; i <= n; i++)
		printf("%c", a[(i - 1) % k + 1]);
	exit(0);
}
void output(int t)
{
	a[t]++;
	for(int i = t + 1; i <= k; i++)
		a[i] = '0';
	output();
}
bool search(int t)
{
	if(t > n)
		output();
	if(t > k)
	{
		if(a[t] < a[t - k])
			output();
		if(a[t] == a[t - k])
			if(search(t + 1))
				return true;
		return false;
	}
	if(search(t + 1))
		return true;
	if(a[t] == '9')
		return false;
	output(t);
	return true;
}
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", a + 1);
	search(1);
	return 0;
}