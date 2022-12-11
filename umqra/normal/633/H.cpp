#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <immintrin.h>
using namespace std;

#ifdef _MSC_VER	
	#define ALIGN(x) __declspec(align(x))
	#define ATTR
#else
	#define ALIGN(x) __attribute__((aligned(x)))
	#define ATTR __attribute__((target("avx")))
#endif

const int N = (int)1e5 + 10;

typedef __m128i Vec;

struct Item
{
	int id, value, mValue;
	Item () : id(), value(), mValue() {}
	Item (int _id, int _value, int _m) : id(_id), value(_value), mValue(_m) {} 
	bool operator < (const Item &x) const
	{
		return value < x.value || (value == x.value && id < x.id);
	}
};

typedef long long ll;

Item a[N];
ALIGN(16) short f[N];
ALIGN(16) short f_skip[2 * N];
int n, m, q;

ATTR void print(Vec x)
{
	printf("%d %d %d %d\n", 
	_mm_extract_epi32(x, 0),
	_mm_extract_epi32(x, 1),
	_mm_extract_epi32(x, 2),
	_mm_extract_epi32(x, 3));
}

ATTR void print16(Vec x)
{
	printf("%d %d %d %d | %d %d %d %d\n", 
	_mm_extract_epi16(x, 0),
	_mm_extract_epi16(x, 1),
	_mm_extract_epi16(x, 2),
	_mm_extract_epi16(x, 3),
	_mm_extract_epi16(x, 4),
	_mm_extract_epi16(x, 5),
	_mm_extract_epi16(x, 6),
	_mm_extract_epi16(x, 7));
}

#define SHUFFLE(a,b,c,d) (a*4*4*4+b*4*4+c*4+d)

ATTR int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		a[i].id = i;
		scanf("%d", &a[i].value);
		a[i].mValue = a[i].value % m;
	}
	f[0] = f[1] = 1;
	for (int i = 2; i < N; i++)
		f[i] = ((int)f[i - 1] + (int)f[i - 2]) % m;
		
	sort(a, a + n);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		int p = -1;
		int k = 0;
		int ans = 0;
		const Vec* f_cur = (const Vec*)f;
		ALIGN(16) short arr[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		int cnt = 0;
		Vec result1 = _mm_set1_epi32(0);
		Vec result2 = _mm_set1_epi32(0);
		for (int s = 0; s < n; s++)
		{
			if (a[s].id >= l && a[s].id <= r && a[s].value != p)
			{
				p = a[s].value;
				arr[cnt & 7] = a[s].mValue;
				cnt++;
				if ((cnt & 7) == 0)
				{
					Vec A1 = _mm_load_si128((const Vec*)arr);
					Vec B1 = _mm_load_si128(f_cur);
					//print16(A1);
					//print16(B1);
					//print(_mm_madd_epi16(A1, B1));
					//print16(A1);
					//print16(B1);
					A1 = _mm_madd_epi16(A1, B1);
					//print(A1);
					//print(_mm_shuffle_epi32(A1, SHUFFLE(2, 3, 0, 1)));
					result1 = _mm_add_epi64(result1, _mm_cvtepi32_epi64(A1));
					result2 = _mm_add_epi64(result2, _mm_cvtepi32_epi64(_mm_shuffle_epi32(A1, SHUFFLE(0, 1, 3, 2))));
					f_cur++;				
				}
			}
		}
		ll* it = (ll*)&result1;
		ans = (*it + *(it + 1)) % m;
		it = (ll*)&result2;
		ans = (ans + *it + *(it + 1)) % m;
		
		short *ptr = (short*)f_cur;
		
		for (int s = 0; s < (cnt & 7); s++)
		{
			ans = (ans + ptr[s] * arr[s]) % m;
		}
		printf("%d\n", ans);
	}
	return 0;
}