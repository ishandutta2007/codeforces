#include<cstdio>
#include<bitset>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,prime[10005],num;
bool flag[7005],mu[7005];
bitset<7005>s[100005],mu2[7005],tmp;
int main()
{
	mu[1]=1;
	flag[1]=1;
	for(int i=2;i<=7000;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			mu[i]=1;
		}
		for(int j=1;j<=num&&prime[j]*i<=7000;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=mu[i]&mu[prime[j]];
		}
	}
	for(int i=1;i<=7000;i++)
	  for(int j=1;j*i<=7000;j++)
	    mu2[i][j*i]=mu[j];
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int opt,x,y,z;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)
		{
			s[x].reset();
			for(int j=1;j*j<=y;j++)
			{
				if(y%j==0)s[x][j]=1,s[x][y/j]=1;
			}
		}
		if(opt==2)
		{
			scanf("%d",&z);
			s[x]=s[y]^s[z];
		}
		if(opt==3)
		{
			scanf("%d",&z);
			s[x]=s[y]&s[z];
		}
		if(opt==4)
		{
			tmp=mu2[y]&s[x];
			if(tmp.count()&1)putchar('1');
			else putchar('0');
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=6;j++)
//			  putchar(s[i][j]+'0');
//			putchar('\n');
//		}
	}
	return 0;
}