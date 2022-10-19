#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],n,q;
set<int>s;
int check(int k)
{
	return a[k]&&(b[k-1]||b[k]||b[k+1]);
}
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==1)
		{
			if(a[y]==1)
			{
				a[y]=0;
				s.erase(y);
			}
			else
			{
				a[y]=1;
				if(b[y-1]||b[y]||b[y+1])
					s.insert(y);
			}
		}
		else
		{
			if(b[y]==1)
			{
				b[y]=0;
				for(int i=y-1;i<=y+1;i++)
					if(1<=i&&i<=n)
						if(!check(i))
							s.erase(i);
			}
			else
			{
				b[y]=1;
				for(int i=y-1;i<=y+1;i++)
					if(1<=i&&i<=n)
						if(check(i))
							s.insert(i);
			}
		}
		puts(s.size()?"NO":"YES");
	}
	return 0;
}