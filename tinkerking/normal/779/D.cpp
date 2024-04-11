#include <bits/stdc++.h>

using namespace std;

char P[200010],T[200010];
int N,M;
int t[200010];

bool check(int x)
{
	//printf("%d Check\n",x);
	int now = 1;
	for (int i=1;i<=N;i++)
	{
		if (t[i]<=x) continue;
		if (P[i]==T[now]) now++; 
		//printf("%d %d\n",i,now);
		if (now>M) break;
	}
	return now>M;
}

int main()
{
	scanf("%s\n%s",P+1,T+1);
	N = strlen(P+1);
	M = strlen(T+1);
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		t[tmp] = i;
		//scanf("%d",&t[i]);
	}
	//printf("%d %d\n",N,M);
	int L = 0,R = N;
	while(L<R-1)
	{
		int mid = (L+R)>>1;
		if (check(mid)) 
			L = mid;
		else
			R = mid;
	}
	printf("%d\n",L);
}