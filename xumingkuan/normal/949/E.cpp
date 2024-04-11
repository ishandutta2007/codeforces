#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
const int MAXN = 101010, NUM = (1 << 17), N = (1 << 18) + 5;
int n, a[MAXN], ans = 233;
bool f[20][N];
int ansvec[233], nowans = 0, output[233];
void search(int p)
{
	if(p == 17)
	{
		if(f[p][0])
			ansvec[++nowans] = -(1 << p);
		if(f[p][2])
			ansvec[++nowans] = (1 << p);
		if(nowans < ans)
		{
			ans = nowans;
			memcpy(output, ansvec, (ans + 1) * sizeof(int));
		}
		if(f[p][0])
			nowans--;
		if(f[p][2])
			nowans--;
		return;
	}
	bool flag = false;
	for(int i = 1; i <= (1 << (18 - p)); i += 2)
		if(f[p][i])
		{
			flag = true;
			break;
		}
	if(!flag)//this digit is not necessary
	{
		for(int i = 0; i <= (1 << (17 - p)); i++)
			f[p + 1][i] = f[p][i << 1];
		return search(p + 1);
	}
	//add 1
	f[p + 1][0] = f[p][0];
	for(int i = 1; i <= (1 << (17 - p)); i++)
		f[p + 1][i] = f[p][i << 1] || f[p][(i << 1) - 1];
	ansvec[++nowans] = -(1 << p);
	search(p + 1);
	nowans--;
	//minus 1
	for(int i = 0; i <= (1 << (17 - p)); i++)
		f[p + 1][i] = f[p][i << 1] || f[p][(i << 1) + 1];
	ansvec[++nowans] = (1 << p);
	search(p + 1);
	nowans--;
}
int main()
{
	memset(f, false, sizeof(f));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		f[0][a[i] + NUM] = true;
	}
	search(0);
	printf("%d\n", ans);
	for(int i = 1; i <= ans; i++)
		printf("%d ", output[i]);
	return 0;
}