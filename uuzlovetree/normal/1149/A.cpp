#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define pll pair<ll,ll>
using namespace std;
#define maxn 200005
int n;
int a[maxn];
int c[5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),c[a[i]]++;
	if(c[1]==0)
	{
		for(int i=1;i<=n;++i)printf("2 ");
	}
	else if(c[1]==1)
	{
		if(c[2])printf("2 ");
		printf("1 ");
		for(int i=1;i<=c[2]-1;++i)printf("2 ");
	}
	else if(c[1]==2)
	{
		if(c[2])printf("2 ");
		printf("1 ");
		for(int i=1;i<=c[2]-1;++i)printf("2 ");
		printf("1 ");
	}
	else
	{
		printf("1 1 1 ");
		for(int i=1;i<=c[2];++i)printf("2 ");
		for(int i=1;i<=c[1]-3;++i)printf("1 ");
	}
	return 0;
}