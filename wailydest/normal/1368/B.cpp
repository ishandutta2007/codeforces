#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10;

long long power(int a) 
{
	long long r = 1;
	for (int i = 0; i < N; ++i) r *= a;
	return r;
}

int main() 
{
	long long k;
	scanf("%lld", &k);
	char s[11];
	strcpy(s, "codeforces");
	int t = 1;
	while (power(t) <= k) ++t;
	--t;
	int amt = 0;
	long long x = power(t);
	while (x < k) {
		++amt;
		x = 1;
		for (int i = 1; i <= 10; ++i) {
			if (i <= amt) x *= t + 1;
			else x *= t;
		}
	}
	for (int i = 1; i <= 10; ++i) {
		int k = i <= amt ? t + 1 : t;
		for (int j = 0; j < k; ++j) printf("%c", s[i - 1]);
	}
	printf("\n");
	return 0;
}