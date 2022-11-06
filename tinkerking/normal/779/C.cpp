#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;

struct item
{
	int A,B,D;
}v[200010];

bool cmp(item a,item b)
{
	return a.D<b.D;
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)scanf("%d",&v[i].A);
	for (int i=1;i<=N;i++)scanf("%d",&v[i].B);
	for (int i=1;i<=N;i++)v[i].D = v[i].A - v[i].B;
	int ans = 0;
	sort(v+1,v+N+1,cmp);
	for (int i=1;i<=K;i++)ans+=v[i].A;
	for (int i=K+1;i<=N;i++)ans+=min(v[i].A,v[i].B);
	printf("%d\n",ans);
}