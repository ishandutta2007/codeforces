#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
const int L=30;
int a[N],Gauss[L],sz;
bool Add(int x)
{
	for(int i=L-1;~i;i--)
	{
        if((x>>i)&1)
		{
			if(Gauss[i]) x^=Gauss[i];
			else
			{
				Gauss[i]=x;
				sz++;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int n,i,x=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		x^=a[i];
		a[i]^=a[i-1];
	}
	for(i=n;i>=1;i--)
	{
		Add(a[i]);
	}
	if(x==0) printf("-1\n");
	else printf("%i\n",sz);
	return 0;
}