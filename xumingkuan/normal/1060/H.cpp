#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cassert>
using namespace std;
int d, p;
long long quickmul(int a, int b)
{
	long long ret = 1;
	for(; b; b >>= 1, a = (long long)a * a % p)
		if(b & 1)
			ret = ret * a % p;
	return ret;
}
int C[15][15];
int a[15][15], ans[15];
map<int, int> numpos;
int used = 3;
int add(int e1, int e2)
{
	printf("+ %d %d %d\n", e1, e2, ++used);
	return used;
}
int pw(int x)
{
	printf("^ %d %d\n", x, ++used);
	return used;
}
int getnum(int x)
{
	if(numpos.find(x) != numpos.end())
		return numpos[x];
	if(x == 0)
		return numpos[x] = getnum(p);
	if(numpos.find(x - 1) != numpos.end())
		return numpos[x] = add(numpos[x - 1], numpos[1]);
	int tmp = getnum(x / 2);
	int ret = numpos[x / 2 * 2] = add(tmp, tmp);
	if(x % 2 == 0)
		return numpos[x] = ret;
	return numpos[x] = add(ret, numpos[1]);
}
int mul(int pos, int val)
{
	if(val == 0)
		return getnum(1);
	int ret = -1;
	for(; val; val >>= 1, pos = add(pos, pos))
		if(val & 1)
		{
			if(ret == -1)
				ret = pos;
			else
				ret = add(ret, pos);
		}
	return ret;
}
int sqr(int x)
{
	int sum = -1;
	for(int i = 0; i <= d; i++)
	{
		if(!ans[i])
			continue;
		int tmp = x;
		if(i > 0)
			tmp = add(x, getnum(i));
		tmp = pw(tmp);
		tmp = mul(tmp, ans[i]);
		if(sum == -1)
			sum = tmp;
		else
			sum = add(sum, tmp);
	}
	return sum;
}
int main()
{
	scanf("%d%d", &d, &p);
	memset(C, 0, sizeof(C));
	for(int i = 0; i <= d; i++)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
	}
	memset(a, 0, sizeof(a));
	for(int i = 0; i <= d; i++)//x^i
	{
		for(int j = 0; j <= d; j++)
			a[i][j] = (a[i][j] + (long long)quickmul(j, d - i) * C[d][i]) % p;
		a[i][d + 1] = (i == 2);
	}
//	for(int i = 0; i <= d; i++, printf("\n"))
//		for(int j = 0; j <= d + 1; j++)
//			printf("%d ", a[i][j]);
	for(int i = 0; i <= d; i++)
	{
		if(a[i][i] == 0)
		{
			int row = i;
			while(row <= d && a[row][i] == 0)
				row++;
			assert(row <= d);
			for(int j = 0; j <= d + 1; j++)
				swap(a[i][j], a[row][j]);
		}
		int tmp = quickmul(a[i][i], p - 2);
		for(int j = d + 1; j >= i; j--)
			a[i][j] = (long long)a[i][j] * tmp % p;
		for(int k = i + 1; k <= d; k++)
			for(int j = d + 1; j >= i; j--)
				a[k][j] = (a[k][j] - (long long)a[k][i] * a[i][j] % p + p) % p;
	}
	for(int i = d; i >= 0; i--)
	{
		ans[i] = a[i][d + 1];
//		printf("%d: %d\n", i, ans[i]);
		for(int j = i - 1; j >= 0; j--)
			a[j][d + 1] = (a[j][d + 1] - (long long)a[j][i] * ans[i] % p + p) % p;
	}
	
	numpos[1] = 3;
	int a2 = sqr(1);
	int b2 = sqr(2);
	int a2b2 = add(a2, b2);
	int x = add(1, 2);
	int x2 = sqr(x);
	int minusa2b2 = mul(a2b2, p - 1);
	int ans2 = add(x2, minusa2b2);
	int ans1 = mul(ans2, (p + 1) / 2);
	printf("f %d\n", ans1);
	return 0;
}