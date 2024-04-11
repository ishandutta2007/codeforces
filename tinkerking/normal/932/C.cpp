#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,A,B;

int main()
{
	scanf("%d%d%d",&N,&A,&B);
	int x,y;
	bool ok = false;
	for (x=0;x*A<=N;x++)
	{
		if ((N - x*A) % B == 0)
		{
			y = (N - x*A) / B;
			ok = true;
			break;
		}
	}
	if (!ok) return 0*puts("-1");
	int now = 0;
	vector<int> ans;
	for (int i=1;i<=x;i++)
	{
		for (int j=now + 2;j<=now + A;j++)ans.push_back(j);
		ans.push_back(now + 1);
		now += A;
	}
	for (int i=1;i<=y;i++)
	{
		for (int j=now + 2;j<=now + B;j++)ans.push_back(j);
		ans.push_back(now + 1);
		now += B;
	}
	
	for (int i=0;i<N;i++)printf("%d%c",ans[i]," \n"[i==N-1]);
}