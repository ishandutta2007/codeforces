#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int x;
int v[3];

int main()
{
	scanf("%d",&N);
	scanf("%d",&x);
	N%=6;
	memset(v,0,sizeof(v));
	v[x] = 1;
	for (int i=N;i>=1;i--)
	{
		if (i%2==1)
			swap(v[0],v[1]);
		else
			swap(v[1],v[2]);
	}
	for (int i=0;i<=2;i++)if (v[i]) printf("%d",i);
}