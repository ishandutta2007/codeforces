#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int tot;
	for(int i=1;i<=k;i++)
	{
		int m;
		scanf("%d",&m);
		int la=-1,cnt=0,mark;
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			if(x!=la+1)	
			{
				cnt++;
				if(cnt==1) mark=x;
				if(cnt==2&&mark==1) tot=j-1;
			}
            la=x;
		}
        if(cnt==1&&mark==1) tot=m;
	}
	printf("%d",n-tot-(k-1)+n-tot);
	return 0;
}