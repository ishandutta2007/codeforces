#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, h, c1, c2, ind, minn;
LL m, res, mm, mini;
vector<PII> V;
PII T[100005];
LL S[100005];

bool cmp(PII x, PII y)
{
	return x.S<y.S;
}

LL bins(int st, LL qwe)
{
	//printf("%d %lld\n", st, qwe);
	if(st==n)
		return h;
	int en=n-1, mid=(st+en)/2, r=V[n-1].F;
	while(st<=en)
	{
		//printf("%d %d %d\n", st, en, mid);
		LL x=(LL)(n-mid)*V[mid].F-S[mid];
		//printf("x=%lld %d %d\n", x, V[mid].F, S[mid]);
		if(x>qwe)
			st=mid+1;
		if(x<=qwe)
		{
			if(mid>0)
				r=max(r, min(V[mid].F+(int)((qwe-x)/(n-mid)), V[mid-1].F));
			else
				r=max(r, V[mid].F+(int)((qwe-x)/(n-mid)));
			en=mid-1;
		}
		mid=(st+en)/2;
	}
//	printf("lol %d\n", r);
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d%d%lld", &n, &h, &c1, &c2, &m);
	mm=m;
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		V.PB(MP(-a, i));
		T[i]=MP(-a, i);
	}
	sort(V.begin(), V.end());
	sort(T, T+n);
	for(int i=n-1; i>=0; i--)
		S[i]=S[i+1]-V[i].F;
	if((LL)n*h<=S[0]+m)
	{
		printf("%lld\n", (LL)n*c1+(LL)h*c2);
		for(int i=0; i<n; i++)
			printf("%d ", h);
		printf("\n");
		return 0;
	}
	for(int i=0; i<n; i++)
		V[i].F*=-1;
	for(int i=0; i<n; i++)
		T[i].F*=-1;
	for(int i=0; i<=n; i++)
	{
		if(mm<0)
			break;
		mini=bins(i, mm);
		LL r=(LL)i*c1+mini*c2;
		if(r>res)
		{
			ind=i;
			res=r;
			minn=mini;
		}
		mm+=V[i].F;
		mm-=h;
		V[i].F=h;
	}
	for(int i=0; i<ind; i++)
	{
		m+=T[i].F;
		m-=h;
		T[i].F=h;
	}
	for(int i=ind; i<n; i++)
		T[i].F=max(T[i].F, minn);
	sort(T, T+n, cmp);
	printf("%lld\n", res);
	for(int i=0; i<n; i++)
		printf("%d ", T[i].F);
	printf("\n");
	return 0;
}