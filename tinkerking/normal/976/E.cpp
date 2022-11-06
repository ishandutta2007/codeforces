#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL N,A,B;
struct creature
{
	LL hp,dmg;
	LL bonus;
	friend bool operator < (creature a,creature b)
	{
		return a.bonus > b.bonus;
	}
}c[200010];
LL sb[200010];

int main()
{
	scanf("%lld%lld%lld",&N,&A,&B);
	LL S = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&c[i].hp,&c[i].dmg);
		c[i].bonus = c[i].hp - c[i].dmg;
		S += c[i].dmg;
	}
	if (B == 0)
	{
		printf("%lld\n",S);
		return 0;
	}
	A = 1LL << A;
	sort(c+1,c+N+1);
	for (int i=1;i<=N;i++)
	{
		//printf("fuck %lld %lld %lld\n",c[i].bonus,c[i].dmg,c[i].hp);
	}
	for (int i=1;i<=N;i++)sb[i] = sb[i-1] + c[i].bonus;
	LL ans = S;
	int lastpos = 0;
	for (int i=1;i<=N;i++)if (c[i].bonus >= 0) lastpos = i;
	//printf("lastpos =%d\n",lastpos);
	for (int i=1;i<=N;i++)
	{
		LL ret = S;
		if (c[i].hp * A > c[i].dmg)
		{
			ret -= c[i].dmg;
			ret += c[i].hp * A;
		}
		//printf("fuck %d %lld\n",i,ret);
		if (i > B - 1)
		{
			ret += sb[min(B-1,LL(lastpos))];
		}
		else
		{
			if (lastpos >= B)
			{
				ret += sb[B] - c[i].bonus;
			}
			else
			{
				ret += sb[lastpos];
				if (c[i].bonus > 0)
					ret -= c[i].bonus;
			}
		}
		//printf("ret %d %lld\n",i,ret);
		ans = max(ret,ans);
	}
	printf("%lld\n",ans);
}