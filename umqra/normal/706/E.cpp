#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>
using namespace std;

typedef __m128i Vec;

__attribute__((target("avx"))) void swapRows(int *x, int *y, int len)
{
	for (int i = len - len % 16; i < len; i++)
		swap(x[i], y[i]);
	const Vec* ptr_1 = (const Vec*)x;
	const Vec* ptr_2 = (const Vec*)y;
	for (int i = 0; i < len / 16; i++, ptr_1 += 4, ptr_2 += 4)
	{
		Vec A = _mm_loadu_si128(ptr_1);
		Vec B = _mm_loadu_si128(ptr_1 + 1);
		Vec C = _mm_loadu_si128(ptr_1 + 2);
		Vec D = _mm_loadu_si128(ptr_1 + 3);
				
		_mm_storeu_si128((Vec*)ptr_1, _mm_loadu_si128(ptr_2));
		_mm_storeu_si128((Vec*)ptr_1 + 1, _mm_loadu_si128(ptr_2 + 1));
		_mm_storeu_si128((Vec*)ptr_1 + 2, _mm_loadu_si128(ptr_2 + 2));
		_mm_storeu_si128((Vec*)ptr_1 + 3, _mm_loadu_si128(ptr_2 + 3));
		
		_mm_storeu_si128((Vec*)ptr_2, A);
		_mm_storeu_si128((Vec*)ptr_2 + 1, B);
		_mm_storeu_si128((Vec*)ptr_2 + 2, C);
		_mm_storeu_si128((Vec*)ptr_2 + 3, D);
	}
}

int arr[1010][1010];

char str[100000];

int main()
{
	int n, m;
	int q;
	scanf("%d%d", &n, &m);
	scanf("%d\n", &q);		
	for (int i = 0; i < n; i++)
	{
		gets(str);
		int value = 0;
		char *ptr = str;
		int it = 0;
		while (*ptr)
		{
			if (*ptr == ' ')
			{
				arr[i][it++] = value;
				value = 0;
			}
			else
				value = (10 * value + *ptr - '0');
			ptr++;
		}
		arr[i][it++] = value;
	}
	
	for (int i = 0; i < q; i++)
	{
		int a, b, c, d, w, h;
		scanf("%d%d%d%d %d%d", &a, &b, &c, &d, &h, &w);
		a--, b--, c--, d--;
		for (int s = 0; s < h; s++)
		{
			swapRows(arr[a + s] + b, arr[c + s] + d, w);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < m; s++)
			printf("%d ", arr[i][s]);
		puts("");
	}
	
	return 0;
}