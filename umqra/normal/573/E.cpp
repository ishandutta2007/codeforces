//http://codeforces.com/contest/573/problem/E

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <immintrin.h>
#include <smmintrin.h>
#include <emmintrin.h>


using namespace std;

typedef long long ll;
const int N = (1 << 17);
alignas(16) int a[N];
int n;

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

const ll INF = (ll)1e18;
ll dp[N];
alignas(16) int inc[2 * N];

__attribute((target("avx2"))) void solve()
{
	while (n % 4 != 0)
		n++;
	for (int i = 0; i < N; i++)
	{
		dp[i] = -INF;	
		inc[2 * i] = i;
	}
	dp[1] = 0;
		
	for (int id = 0; id < n; id++)
	{
		__m128i curMult = _mm_set1_epi32(a[id]);
		const __m128i* p = (const __m128i*)inc;
		const __m128i* d = (const __m128i*)dp;
		p++;
		d++;
		int i;
		__m128i x1 = _mm_set_epi64x(dp[1] + a[id], dp[0]);
		for (i = 2; i <= id + 1; i += 4, p += 2, d += 2)
		{
			__m128i A1 = _mm_load_si128(p);
			__m128i A2 = _mm_load_si128(p + 1);
			
			__m128i multed1 = _mm_mul_epi32(curMult, A1);
			__m128i multed2 = _mm_mul_epi32(curMult, A2);
			
			multed1 = _mm_add_epi64(multed1, _mm_load_si128(d));
			multed2 = _mm_add_epi64(multed2, _mm_load_si128(d + 1));
			
			const __m128i* dp_prev_u = (const __m128i*)(dp + i - 1);
			__m128i dp_prev_value = _mm_loadu_si128(dp_prev_u);
			__m128i comp_prev = _mm_cmpgt_epi64(x1, dp_prev_value);
			__m128i result = _mm_or_si128(_mm_and_si128(comp_prev, x1), _mm_andnot_si128(comp_prev, dp_prev_value));
			_mm_storeu_si128((__m128i*)dp_prev_u, result);
			
			const __m128i* dp_u = (const __m128i*)(dp + i + 1);
			__m128i dp_u_value = _mm_loadu_si128(dp_u);
			__m128i comp = _mm_cmpgt_epi64(multed1, dp_u_value);
			result = _mm_or_si128(_mm_and_si128(comp, multed1), _mm_andnot_si128(comp, dp_u_value));
			_mm_storeu_si128((__m128i*)dp_u, result);
			
			x1 = multed2;
		}
		const __m128i* last_dp = (const __m128i*)(dp + i - 1);
		__m128i last_dp_value = _mm_loadu_si128(last_dp);
		__m128i last_comp = _mm_cmpgt_epi64(x1, last_dp_value);
		__m128i result = _mm_or_si128(_mm_and_si128(last_comp, x1), _mm_andnot_si128(last_comp, last_dp_value));
		_mm_storeu_si128((__m128i*)last_dp, result);	
		
	}
	ll ans = 0;
	for (int i = 1; i <= n + 1; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
}

int main()
{
	read();
	solve();
	return 0;
}