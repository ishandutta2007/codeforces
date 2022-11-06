#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,S[2][10];

int main()
{
	scanf("%d",&N);
	for (int j=0;j<2;j++)
	{
		for (int i=1;i<=N;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			S[j][tmp]++;
		}
	}
	for (int i=1;i<=5;i++)
	if ((S[0][i]+S[1][i])%2!=0) 
	{
		puts("-1");
		return 0;
	}
	int ans = 0;
	for (int i=1;i<=5;i++)
	{
		ans+=max(S[0][i],S[1][i])-(S[0][i]+S[1][i])/2;
	}
	ans/=2;
	printf("%d\n",ans);
}