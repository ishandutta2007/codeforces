#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
    	scanf("%d",&n);
    	int u;
    	for(long long i=1;;i++)
    	{
    		if(i*i<=n) u=i;
    		else break;
		}
		int v;
		for(long long i=1;;i++)
    	{
    		if(i*i*i<=n) v=i;
    		else break;
		}
		int w;
		for(long long i=1;;i++)
    	{
    		if(i*i*i*i*i*i<=n) w=i;
    		else break;
		}
		printf("%d",u+v-w);
		if(j<t) printf("\n");
	}
	return 0;
}