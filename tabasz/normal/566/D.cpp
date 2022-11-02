#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 
const int M=1024*256;

int n, q;
int D[2*M];
int T[M];

int find(int a)
{
	if(T[a]==a) return a;
	else return T[a]=find(T[a]);
}


void onion(int a, int b)
{
	a=find(a);
	b=find(b);
	T[a]=b;
}

void add(int v, int w)
{
	v+=M;
	D[v]=w;
	while(v>1)
	{
		v/=2;
		D[v]=-1;
		if(D[2*v+1]!=-1)
			D[v]=D[2*v+1];
		if(D[2*v]!=-1)
			D[v]=D[2*v];	
	}
}

int mini(int v, int vp, int vk, int p, int k)
{
	if(vp>k || vk<p)
		return -1;
	if(vp>=p && vk<=k)
		return D[v];
	int mid=(vp+vk)/2;
	int qwe=mini(2*v, vp, mid, p, k);
	if(qwe!=-1)
		return qwe;
	return mini(2*v+1, mid+1, vk, p, k);
}

int main()
{
	for(int i=0; i<M; i++)
		add(i, -1);
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++)
		add(i-1, i-1);
	for(int i=1; i<=n; i++)
		T[i-1]=i-1;
	for(int i=0; i<q; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		b--;
		c--;
		if(c<b) swap(b, c);
		if(a==1)
		{
			if(find(b)!=find(c))
			{
				onion(b, c);
				add(b, b);
				add(c, c);
			}
		}
		if(a==2 && b<c)
		{
			int x=mini(1, 0, M-1, b, c-1);
			while(x!=-1)
			{
				onion(x, c);
				add(x, -1);
				x=mini(1, 0, M-1, b, c-1);
			}
		}
		if(a==3)
		{
			if(find(b)==find(c))
				printf("YES\n");
			else 
				printf("NO\n");
		}
	}
	return 0;
}