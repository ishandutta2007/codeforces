#include <bits/stdc++.h>
using namespace std;


int main()
{
	for (int i = 1; i <= 2230; i++)
		putchar(i == 2230 ? '1' : (i <= 1115 ? '9' : '0'));
	puts("");
	for (int i = 1116; i <= 2230; i++)
		putchar('9');
	return 0;
}