#include <cstdio>
using namespace std;

const int md = 1000000007;

inline int add(int a, int b) 
{
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int mul(int a, int b)
{
	return (int)((long long)a * b % md);
}

const int N = 2000000;
int state[N + 1];

void init() 
{
	state[1] = 0;
	state[2] = 0;
	state[3] = 1;
	state[4] = 1;
	state[5] = 3;
	state[6] = 6;
	for (int i = 6; i <= N; ++i) state[i] = add(add(state[i - 1], mul(state[i - 2], 2)), !(i % 3));
}

int main() 
{
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", mul(state[n], 4));
	}
	return 0;
}