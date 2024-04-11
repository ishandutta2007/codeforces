#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 100100;
int n;
char s[N];

int main()
{
	scanf(" %d %s", &n, s);
	int bal = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'A')
			bal++;
		else
			bal--;
	if (bal > 0)
		printf("Anton\n");
	else if (bal == 0)
		printf("Friendship\n");
	else
		printf("Danik\n");


	return 0;
}