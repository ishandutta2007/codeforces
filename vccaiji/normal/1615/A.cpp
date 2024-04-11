#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    	scanf("%d",&n);
    	long long s=0;
    	for(int j=1;j<=n;j++)
    	{
    		int a;
    		scanf("%d",&a);
    		s+=a;
		}
		if(s%n==0) printf("0");
		else printf("1");
		if(i<t) printf("\n");
	}
	return 0;
}