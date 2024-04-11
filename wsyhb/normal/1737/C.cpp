#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int r[3],c[3];
		for(int i=0;i<3;++i)
			scanf("%d%d",r+i,c+i);
		int x,y;
		scanf("%d%d",&x,&y);
		bool ans=false;
		for(int i=0;i<3;++i)
		{
			if(x%2==r[i]%2&&y%2==c[i]%2)
			{
				ans=true;
				break;
			}
		}
		if(!ans)
		{
			puts("NO");
			continue;
		}
		typedef pair<int,int> P;
		vector<P> pos(3);
		for(int i=0;i<3;++i)
			pos[i]=P(r[i],c[i]);
		sort(pos.begin(),pos.end());
		if(pos[0]==P(1,1)&&pos[1]==P(1,2)&&pos[2]==P(2,1))
			ans=(x==1||y==1);
		else if(pos[0]==P(1,n-1)&&pos[1]==P(1,n)&&pos[2]==P(2,n))
			ans=(x==1||y==n);
		else if(pos[0]==P(n-1,1)&&pos[1]==P(n,1)&&pos[2]==P(n,2))
			ans=(x==n||y==1);
		else if(pos[0]==P(n-1,n)&&pos[1]==P(n,n-1)&&pos[2]==P(n,n))
			ans=(x==n||y==n);
		puts(ans?"YES":"NO");
	}
	return 0;
}