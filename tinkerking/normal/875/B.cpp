#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
bool ok[300010];
int lastok;

int main()
{
	scanf("%d",&N);
	printf("1");
	lastok = N+1;
	int ans = 1;
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		ok[tmp] = true;
		ans++;
		while(lastok > 1 && ok[lastok-1])
		{
			lastok--;
			ans--;
		}
		printf(" %d",ans);
	}
}