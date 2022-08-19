#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 300300;
int n, a, b;
char s[N];

int main()
{
	scanf("%d%d%d", &n, &a, &b);
	scanf(" %s ", s);
	a--;b--;
	printf("%d\n", abs(s[a] - s[b]));


	return 0;
}