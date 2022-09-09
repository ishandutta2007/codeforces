#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,i;
	int x,y;
	scanf("%i",&n);
	char t;
	int a=0,b=0;
	while(n--)
	{
		scanf("\n%c %i %i",&t,&x,&y);
		if(x>y) swap(x,y);
		if(t=='+')
		{
			a=max(a,x);
			b=max(b,y);
		}
		else
		{
			if(a<=x && b<=y)
			{
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	return 0;
}