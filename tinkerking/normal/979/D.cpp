#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct query
{
	int type;
	int d,x,k;
}q[100010];

int Q;
const int MN = 10000010;
int ch[MN][2];
int mi[MN];
const int split = 300;
int cnt = split;
int root[310];
bool vis[100010];

void insert(int x)
{
	if (vis[x]) return;
	vis[x] = true;
	for (int i=1;i<=split;i++)
	if (x % i == 0)
	{
		int now = root[i];
		mi[now] = min(mi[now],x);
		for (int j=18;j>=0;j--)
		{
			int vx = !!((1 << j) & x);
			if (!ch[now][vx]) 
			{
				ch[now][vx] = ++cnt;
				mi[cnt] = 1e9;
			}
			now = ch[now][vx];
			mi[now] = min(mi[now],x);
		}
	}
}

int query(int x,int k,int d)
{
	if (k <= split)
	{
		int now = root[k];
		if (mi[now] > d) return -1;
		int ans = 0;
		for (int i=18;i>=0;i--)
		{
			int want,ret;
			if ((1 << i) & x) want = 0;
			else want = 1;
			if (mi[ch[now][want]] > d)
			{
				ret = want ^ 1;
			}
			else
			{
				ret = want;
			}
			ans = ans * 2 + ret;
			now = ch[now][ret];
		}
		return ans;
	}
	else
	{
		int ans = -1,mv = -1;
		for (int i=k;i<=100000;i+=k)
		if (vis[i] && i <= d && (i ^ x) > mv)
		{
			ans = i;
			mv = i ^ x;
		}
		return ans;
	}
}

int main()
{
	//freopen("D1.in","r",stdin);
	for (int i=0;i<=cnt;i++)root[i] = i,mi[i] = 1e9;
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		int type,x,k,s;
		scanf("%d",&type);
		if (type == 1)
		{
			scanf("%d",&x);
			insert(x);
		}
		else
		{
			scanf("%d%d%d",&x,&k,&s);
			if (x % k != 0) 
			{
				puts("-1");
				continue;
			}
			int d = s - x;
			printf("%d\n",query(x,k,d));
		}
	}
}