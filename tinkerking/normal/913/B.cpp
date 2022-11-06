#include <bits/stdc++.h>

using namespace std;

int N,s[1010],p[1010],cnt[1010];

int main()
{
	scanf("%d",&N);
	for (int i=2;i<=N;i++)
	{
		scanf("%d",&p[i]);
		s[p[i]]++;
	}
	for (int i=1;i<=N;i++)
	if (!s[i]) cnt[p[i]]++;
	bool ok = true;
	for (int i=1;i<=N;i++)
	if (s[i]) ok &= (cnt[i] >= 3);
	puts(ok?"Yes":"No");
}