//http://codeforces.com/problemset/problem/632/F

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <algorithm>
#include "immintrin.h"

using namespace std;

typedef __m128i Vec;

const int N = 2600;
const int SZ = (int)1e5 + 10;
char str[SZ];
int n;
alignas(16) int row[N][N];
alignas(16) int col[N][N];

void read()
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		gets(str);
		int len = strlen(str);
		int number = 0;
		int id = 0;
		for (int s = 0; s < len; s++)
		{
			if (str[s] == ' ')
			{
				row[i][id++] = number;
				number = 0;
			}
			else
				number = number * 10 + (str[s] - '0');
		}
		row[i][id++] = number;
	}
	for (int i = 0; i < n; i++)
		for (int s = 0; s < n; s++)
			col[s][i] = row[i][s];
}

__attribute((target("avx"))) void solve()
{
	bool ok = true;
	for (int i = 0; i < n && ok; i++)
	{
		if (row[i][i] != 0)
			ok = false;
		for (int s = i + 1; s < n && ok; s++)
		{
			if (row[i][s] != row[s][i])
				ok = false;
			Vec value = _mm_set1_epi32(row[i][s]);
			const Vec* ptrRow = (const Vec*)row[i];
			const Vec* ptrCol = (const Vec*)col[s];
			int block = n / 8;
			
			for (int a = 0; a < block; a++, ptrRow += 2, ptrCol += 2)
			{
				Vec R1 = _mm_load_si128(ptrRow);
				Vec C1 = _mm_load_si128(ptrCol);
				Vec R2 = _mm_load_si128(ptrRow + 1);
				Vec C2 = _mm_load_si128(ptrCol + 1);
				
				Vec CompR1 = _mm_cmplt_epi32(R1, value);
				Vec CompC1 = _mm_cmplt_epi32(C1, value);
				
				Vec CompR2 = _mm_cmplt_epi32(R2, value);
				Vec CompC2 = _mm_cmplt_epi32(C2, value);
				
				Vec Res1 = _mm_and_si128(CompR1, CompC1);
				Vec Res2 = _mm_and_si128(CompR2, CompC2);
				Res1 = _mm_or_si128(Res1, Res2);
				
				if (_mm_testz_si128(Res1, Res1) != 1)
				{
					ok = false;
					break;
				}
			}
			for (int k = block * 8; k < n; k++)
			{
				if (row[i][s] > max(row[i][k], row[k][s]))
				{
					ok = false;
					break;
				}
			}
		}
	}
	printf("%s\n", ok ? "MAGIC" : "NOT MAGIC");
}

int main()
{
	read();
	solve();
	return 0;
}