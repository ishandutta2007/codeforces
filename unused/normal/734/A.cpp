#include "bits/stdc++.h"
using namespace std;

char dat[100005];
int cnt[256];

int main()
{
	int n;
	scanf("%d%s", &n, dat);
	for (int i = 0; dat[i]; i++)
	{
		cnt[dat[i]]++;
	}

	if (cnt['A'] > cnt['D']) puts("Anton");
	else if (cnt['A'] < cnt['D']) puts("Danik");
	else puts("Friendship");
}