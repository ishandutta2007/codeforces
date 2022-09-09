#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,l,r,x;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i %i",&l,&r,&x);
		if(x>=l && x<=r)
		{
			int a=r+x-(r%x);
			printf("%i\n",a);
		}
		else printf("%i\n",x);
	}
	return 0;
}