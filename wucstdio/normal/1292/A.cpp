#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,num;
bool f[2][100005];
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		f[x][y]^=1;
		if(f[x][y])
		{
			if(f[x^1][y])num++;
			if(f[x^1][y-1])num++;
			if(f[x^1][y+1])num++;
		}
		else
		{
			if(f[x^1][y])num--;
			if(f[x^1][y-1])num--;
			if(f[x^1][y+1])num--;
		}
		if(!num)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}