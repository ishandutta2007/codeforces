#include <bits/stdc++.h>
using namespace std;
pair<int,int>pos;
map<int,bool>mp[100010];
int main()
{
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
	{
        scanf("%d %d",&a,&b);
        if(a>b)
		swap(a,b);
        mp[a][b]=1;
    }
    if(1ll*n*(n-1)/2<=1ll*m)
	{
		printf("NO\n");
		return 0;
	}
    printf("YES\n");
    int c=0;
    while(1)
	{
        a=(rand()%n)+1;
        b=(rand()%n)+1;
        if(a==b)
			continue;
        if(a>b)swap(a,b);
        if(mp[a][b]==0)
			break;
    }
    for(int i=1,va=1;i<=n;i++)
	{
        if(i==a)
			printf("%d ",n-1);
        else if(i==b)
			printf("%d ",n);
        else 
			printf("%d ",va++);
    }
    printf("\n");
    for(int i=1,va=1;i<=n;i++)
	{
        if(i==a)
			printf("%d ",n);
        else if(i==b)
			printf("%d ",n);
        else 
			printf("%d ",va++);
	}
    printf("\n");
    return 0;
}