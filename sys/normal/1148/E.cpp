#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
int n,s[Maxn],T[Maxn];
long long sum;
struct sor
{
	int val,id;
	bool operator < (const sor &tmp) const
	{
		return val<tmp.val;
	}
}S[Maxn];
queue <int> Qu;
int cnt,X[5*Maxn],Y[5*Maxn],D[5*Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&T[i]);
	for(int i=1;i<=n;i++)
		S[i]=(sor){s[i],i};
	sort(S+1,S+1+n);
	sort(T+1,T+1+n);
	for(int i=1;i<=n;i++)
	{
		sum+=S[i].val-T[i];
		if(sum>0)
		{
			printf("NO");
			return 0;
		}
	}
	if(sum)
	{
		printf("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(S[i].val>T[i]) Qu.push(i);
	for(int i=1;i<=n;i++)
	{
		if(S[i].val>=T[i]) continue;
		int now=Qu.front();
		while(S[now].val-T[now]<T[i]-S[i].val)
		{
			X[++cnt]=S[i].id,Y[cnt]=S[now].id,D[cnt]=S[now].val-T[now];
			S[i].val+=S[now].val-T[now],S[now].val=T[now];
			Qu.pop();
			now=Qu.front();
		}
		if(S[i].val!=T[i])
		{
			X[++cnt]=S[i].id,Y[cnt]=S[now].id,D[cnt]=T[i]-S[i].val;
			S[now].val-=T[i]-S[i].val,S[i].val=T[i];
			if(S[now].val==T[now]) Qu.pop();
		}
	}
	for(int i=1;i<=cnt;i++)
		if(D[i]<=0)
		{
			printf("NO");
			return 0;
		}
	printf("YES\n%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d %d\n",X[i],Y[i],D[i]);
	return 0;
}