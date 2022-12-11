#include <bits/stdc++.h>
using namespace std;

int dat[15];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &dat[i]);
	sort(dat, dat + n);
volatile int foo = 0;
while (foo <= 1000000000) ++foo;
	for (int i = 0; i < n; i++) printf("%d ", dat[i]);
}