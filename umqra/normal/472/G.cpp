//http://codeforces.com/problemset/problem/472/G

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <immintrin.h>
#include <smmintrin.h>
using namespace std;

#ifdef _MSC_VER
	#define ALIGN(x) __declspec(align(x))
	#define ATTR 
#else
	#define ALIGN(x) __attribute((aligned(x)))
	#define ATTR __attribute__((target("avx")))
#endif

const int SHIFTS = 128;
const int N = (int)2e5 + 10;
const int T = (N / SHIFTS + 1) * SHIFTS;

typedef unsigned int uint;
typedef __m128i Vec;

struct BitSet
{
	ALIGN(16) uint a[T];
	BitSet()
	{
		memset(a, 0, sizeof(a));
	}
	void set(int pos)
	{
		a[pos >> 5] |= ((uint)1 << (uint)(pos & 31));
	}
	int get(int pos)
	{
		return (a[pos >> 5] >> (uint)(pos & 31)) & 1;
	}
};

BitSet A[SHIFTS];
BitSet B[SHIFTS];

const int BITS = 16;
const int SIZE = (1 << BITS);
const int MASK = SIZE - 1;
int cnt[SIZE];

static inline int32_t __attribute__((always_inline))
mm_popcnt_u32(uint32_t x){
	int32_t result;
	__asm__("popcnt %1, %0" : "=r" (result) : "r" (x));
	return result;
}

ATTR int getDistance(BitSet &a, BitSet &b, int pa, int pb, int len)
{
	int rem = len % 256;
	int blocks256 = len / 256;
	Vec *ptr_a = (Vec*)(a.a + pa / 32);
	Vec *ptr_b = (Vec*)(b.a + pb / 32);
	int sum[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < blocks256; i++, ptr_a += 2, ptr_b += 2)
	{
		Vec X1 = _mm_stream_load_si128(ptr_a);
		Vec X2 = _mm_stream_load_si128(ptr_a + 1);
		Vec Y1 = _mm_stream_load_si128(ptr_b);
		Vec Y2 = _mm_stream_load_si128(ptr_b + 1);
		X1 = _mm_xor_si128(X1, Y1);
		X2 = _mm_xor_si128(X2, Y2);
		sum[0] += mm_popcnt_u32(_mm_extract_epi32(X1, 0));
		sum[1] += mm_popcnt_u32(_mm_extract_epi32(X1, 1));
		sum[2] += mm_popcnt_u32(_mm_extract_epi32(X1, 2));
		sum[3] += mm_popcnt_u32(_mm_extract_epi32(X1, 3));
		sum[4] += mm_popcnt_u32(_mm_extract_epi32(X2, 0));
		sum[5] += mm_popcnt_u32(_mm_extract_epi32(X2, 1));
		sum[6] += mm_popcnt_u32(_mm_extract_epi32(X2, 2));
		sum[7] += mm_popcnt_u32(_mm_extract_epi32(X2, 3));
	}
	//int ans = sum[0] + sum[1] + sum[2] + sum[3];
	int ans = sum[0] + sum[1] + sum[2] + sum[3] + 
			sum[4] + sum[5] + sum[6] + sum[7];
	int i;
	for (i = blocks256 * 256; i + 32 <= len; i += 32)
		ans += mm_popcnt_u32(a.a[(pa + i) / 32] ^ b.a[(pb + i) / 32]);
	for (; i < len; i++)
		ans += (a.get(pa + i) ^ b.get(pb + i));
	return ans;
}

char str[N];

void read(BitSet *b)
{
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < SHIFTS; i++)
	{
		for (int s = i; s < len; s++)
		{
			if (str[s] == '1')
				b[i].set(s - i);
		}
	}
}

int main()
{
	for (int i = 1; i < SIZE; i++)
	{
		cnt[i] = cnt[i & (i - 1)] + 1;
	}
	read(A);
	read(B);
	int q;
	scanf("%d\n", &q);
	for (int i = 0; i < q; i++)
	{
		int p1 = -1, p2 = -1, len = -1;
		gets(str);
		int ptr = 0;
		int strLen = strlen(str);
		int value = 0;
		str[strLen] = ' ';
		str[strLen + 1] = 0;
		strLen++;
		while (ptr < strLen)
		{
			if (str[ptr] == ' ')
			{
				if (p1 == -1)
					p1 = value;
				else if (p2 == -1)
					p2 = value;
				else
					len = value;
				value = 0;
			}
			else
				value = value * 10 + (str[ptr] - '0');
			ptr++;
		}
		int r1 = p1 % SHIFTS;
		int r2 = p2 % SHIFTS;
		
		printf("%d\n", getDistance(A[r1], B[r2], p1 - r1, p2 - r2, len));
	}
	return 0;
}