#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,a[N],p[3][N],h[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
char s[N];
int main()
{
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]-'a';
	for(int x=0;x<3;x++)
	{
		for(int i=1;i<=n;i++)
		{
			p[x][i]=(a[i]!=x);
			if(i>3)
				p[x][i]+=p[x][i-3];
		}
	}
	while(q--)
	{
		int l,r,ans=INT_MAX;
		scanf("%d%d",&l,&r);
		for(int b=0;b<6;b++)
		{
			int c=0,al=l,ar=r;
			for(int t=0;t<3;t++)
			{
				int x=h[b][t];
				ar=r;
				while(al%3!=ar%3)
					ar--;
				c+=p[x][ar];
				if(al-3>0)
					c-=p[x][al-3];
				al++;
				if(al>r)
					break;
			}
			ans=min(ans,c);
			
		}
		printf("%d\n",ans);
	}
	return 0;
}