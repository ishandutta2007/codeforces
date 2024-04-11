#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,xx,yy;
bool visx[101],visy[101];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		int x,y;
        scanf("%d%d",&x,&y);
        if(!visx[x])
		{
			xx++;
		}
        if(!visy[y])
		{
			yy++;
		}
        visx[x]=1;
		visy[y]=1;
    }
    printf("%d",min(xx,yy));
    return 0;
}