#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 200200;
int n;
char s[N];

int main()
{
	scanf("%d %s", &n, s);
	int p = 0, q = n;
	while(p < n && s[p] == '<') p++;
	while(q > 0 && s[q - 1] == '>') q--;
	printf("%d\n", p + n - q);

	return 0;
}