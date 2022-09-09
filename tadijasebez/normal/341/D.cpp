#include <stdio.h>
#define ll long long
const int N=1050;
struct BIT
{
	ll sum[N][N];
	BIT(){ for(int i=0;i<N;i++) for(int j=0;j<N;j++) sum[i][j]=0;}
	void Set(int x, int y, ll f){ for(int i=x;i<N;i+=i&-i) for(int j=y;j<N;j+=j&-j) sum[i][j]^=f;}
	void Set(int x1, int y1, int x2, int y2, ll f){ Set(x1,y1,f);Set(x1,y2+1,f);Set(x2+1,y1,f);Set(x2+1,y2+1,f);}
	ll Get(int x, int y){ ll ret=0;for(int i=x;i;i-=i&-i) for(int j=y;j;j-=j&-j) ret^=sum[i][j];return ret;}
} Tree[4];
int type[N][N],cnt[4][N][N];
int main()
{
	int n,q,i,j;
	scanf("%i %i",&n,&q);
	for(i=0;i<=n+5;i+=2) for(j=0;j<=n+5;j+=2)
	{
		type[i][j]=0,type[i+1][j]=1,type[i][j+1]=2,type[i+1][j+1]=3;
	}
	int x1,y1,x2,y2,t;
	ll val;
	while(q--)
	{
		scanf("%i %i %i %i %i",&t,&x1,&y1,&x2,&y2);
		int H=x2-x1+1,W=y2-y1+1;
		if(t==1)
		{
			x1--;y1--;
			ll sol=Tree[type[x2][y2]].Get(x2,y2)^Tree[type[x1][y2]].Get(x1,y2);
			sol^=Tree[type[x2][y1]].Get(x2,y1)^Tree[type[x1][y1]].Get(x1,y1);
			printf("%lld\n",sol);
		}
		else
		{
			scanf("%lld",&val);
			Tree[type[x1][y1]].Set(x1,y1,x2,y2,val);
			if(H&1)
			{
				Tree[type[x1][y1]].Set(x2+1,y1,n,y2,val);
				Tree[type[x1+1][y1]].Set(x2+1,y1,n,y2,val);
			}
			if(W&1)
			{
				Tree[type[x1][y1]].Set(x1,y2+1,x2,n,val);
				Tree[type[x1][y1+1]].Set(x1,y2+1,x2,n,val);
			}
			if((H&1) && (W&1))
			{
				for(i=0;i<4;i++) Tree[i].Set(x2+1,y2+1,n,n,val);
			}
		}
	}
	return 0;
}