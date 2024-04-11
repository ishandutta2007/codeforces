#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>q;
int main()
{	
	ios::sync_with_stdio(false);
	int n,k;
	long long s,m;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&s,&m);
		if(k)
		{
			printf("%I64d\n",s+m);
			q.push(-(s+m));
			k--;
		}
		else
		{
			long long c=-q.top();
			q.pop();
			printf("%I64d\n",max(c,s)+m);
			q.push(-(max(c,s)+m));
		}
	}
	return 0;
}