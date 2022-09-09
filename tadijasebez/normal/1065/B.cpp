#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;ll m;
	scanf("%i %lld",&n,&m);
    int a=max((ll)0,n-m*2);
    int b=n-1;
    if(m==0) b=n;
    for(int i=1;i<=n;i++)
	{
		if(m>0) m-=i,b--;
	}
	printf("%i %i\n",a,b);
	return 0;
}