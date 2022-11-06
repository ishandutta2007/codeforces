#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	if (N > 30) printf("%d\n",M);
	else
	{
		int v = 1;
		for (int i=1;i<=N;i++)v *= 2;
		printf("%d\n",M % v);
	}
}