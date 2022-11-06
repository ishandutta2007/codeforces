#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

unordered_map<int,LL>T;
struct ring
{
	LL a,b,h;
}R[100010],R2[100010];
bool cmp(ring A,ring B)
{
	if (A.b==B.b) return A.a>B.a;
	return A.b>B.b;
}
int lowbit(int x){return x&-x;}
void add(int x,LL y)
{
	while(x<=1e9)
	{
		if (!T[x]) T[x] = y;
		else T[x] = max(T[x],y);
		x+=lowbit(x);
	}
}
LL get(int x)
{
	LL res = 0;
	while(x)
	{
		if (T[x])
		res = max(res,T[x]);
		x-=lowbit(x);
	}
	return res;
}

int main()
{
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%I64d%I64d%I64d",&R[i].a,&R[i].b,&R[i].h);
	sort(R+1,R+N+1,cmp);
	int cnt = 0;
	LL S = 0;
	R[0].a = R[0].b = R[N+1].a = R[N+1].b = -1;
	for (int i=1;i<=N;i++)
	{
		S+=R[i].h;
		if (R[i].b!=R[i+1].b)
		{
			R2[++cnt] = (ring){R[i].a,R[i].b,S};
			S = 0;
		}
	}
	LL ans = 0,res;
	for (int i=1;i<=cnt;i++)
	{
		res = get(R2[i].b-1) + R2[i].h;
		ans = max(ans,res);
		add(R2[i].a,res);
	}
	printf("%I64d\n",ans);
}