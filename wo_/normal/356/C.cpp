#include<cstdio>
#include<algorithm>

using namespace std;

int a[5];

int solve(int x)
{
	int res=x;
	int tmp[5];
	for(int i=0;i<5;i++) tmp[i]=a[i];
	tmp[1]-=x;tmp[2]-=x;
	tmp[3]+=x;
	int k=tmp[2]/3;
	res+=k*2;
	tmp[3]+=k*2;
	tmp[2]-=k*3;
	
	int m=min(tmp[1],tmp[2]);
	res+=m;
	tmp[1]-=m;tmp[2]-=m;
	tmp[3]+=m;
//	printf("%d %d %d %d %d\n",tmp[1],tmp[2],tmp[3],tmp[4],res);
	if(tmp[2]==0)
	{
		int s=tmp[1]/3;
		res+=s*2;
		tmp[1]-=s*3;
		tmp[3]+=s;
		if(tmp[1]>tmp[3])
		{
			if(tmp[1]==1)
			{
				if(tmp[4]>=2) return res+2;
				return -1;
			}
			if(tmp[1]==2)
			{
				if(tmp[4]>=1) return res+2;
				return -1;
			}
		}
		return res+tmp[1];
	}
	else
	{
		if(tmp[2]==1)
		{
			if(tmp[4]==0)
			{
				if(tmp[3]<2) return -1;
				return res+2;
			}
			return res+1;
		}
		else
		{
			return res+2;
		}
	}
}

int main()
{
	for(int i=0;i<5;i++) a[i]=0;
	int N;
	scanf("%d",&N);
	int total=0;
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		a[in]++;
		total+=in;
	}
	if(total<=2)
	{
		printf("-1\n");
		return 0;
	}
	int ans=-1;
	for(int i=0;i<=min(a[1],a[2]);i++)
	{
		int x=solve(i);
		if(x==-1) continue;
		if(ans==-1||ans>x) ans=x;
	}
	printf("%d\n",ans);
	return 0;
}