#include<bits/stdc++.h>
using namespace std;
const int N=500005,kuai=240;
int a[N],s[kuai+20][kuai+20];
int main()
{
	int q,n=500000;
	scanf("%d",&q);
	while(q--)
	{
		int ty,x,y;
		scanf("%d%d%d",&ty,&x,&y);
		if(ty==1)
		{
			a[x]+=y;
			for(int i=1;i<=kuai;i++)
				s[i][x%i]+=y;
		}
		if(ty==2)
		{
			if(x>kuai)
			{
				int k=0;
				for(int i=y;i<=n;i+=x)
					k+=a[i];
				printf("%d\n",k);
			}
			else
				printf("%d\n",s[x][y]);
		}
	}
	return 0;
}