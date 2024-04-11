#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=2005;
char Base[N][N];
int cnt[N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",Base[i]+1);
		for(j=1;j<=m;j++) cnt[j]+=Base[i][j]-'0';
	}

	for(i=1;i<=n;i++)
	{
		bool ok=1;
		for(j=1;j<=m;j++)
		{
			if(Base[i][j]=='1')
			{
				if(cnt[j]==1) ok=0;
			}
		}
		if(ok) return printf("YES\n"),0;
	}
	printf("NO\n");
	return 0;
}