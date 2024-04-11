#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back

int n, c;
int A[1000005], tmp;
vector<int> V[500005];

void add(int a, int b, int qwe)
{
	if(a<b)
	{
		add(b, a, -1);
		return;
	}
	if(qwe>0)
		tmp++;
	A[c-a+1]+=qwe;
	A[c-b+1]-=qwe;
}

int main()
{
	scanf("%d%d", &n, &c);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		for(int j=0; j<a; j++)
		{
			int x;
			scanf("%d", &x);
			V[i].PB(x);
		}
	}
	for(int i=1; i<n; i++)
	{
		bool boo=1;
		for(int j=0; j<(int)V[i].size(); j++)
		{
			if((int)V[i+1].size()<=j)
				break;
			if(V[i][j]!=V[i+1][j])
			{
				add(V[i][j], V[i+1][j], 1);
				boo=0;
				break;
			}
		}
		if(boo && V[i].size()>V[i+1].size())
		{
			printf("-1\n");
			return 0;
		}
	}
	int lol=0;
	for(int i=0; i<c; i++)
	{
		lol+=A[i];
		if(lol==tmp)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}