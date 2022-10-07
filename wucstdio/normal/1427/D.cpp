#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],b[100005],p[100005];
int tot,res[105][105];
void solve(int x)
{
	int now=0;
	for(int i=1,j=1;i<=res[x][0];i++)
	{
		int l=n-now-res[x][i]+1;
		for(int k=1;k<=res[x][i];k++,j++)
		  b[l+k-1]=a[j];
		now+=res[x][i];
	}
	for(int i=1;i<=n;i++)a[i]=b[i],p[a[i]]=i;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	while(1)
	{
		bool flag=1;
		for(int i=1;i<n;i++)
		{
			if(p[i]>p[i+1])
			{
				tot++;
				res[tot][0]=4;
				res[tot][1]=p[i+1]-1;
				int pos=p[i+1]+1;
				while(a[pos]==a[pos-1]+1)pos++;
				res[tot][2]=pos-p[i+1];
				res[tot][3]=p[i]-pos+1;
				res[tot][4]=n-p[i];
				if(res[tot][4]==0)res[tot][0]--;
				if(res[tot][1]==0)
				{
					res[tot][0]--;
					res[tot][1]=res[tot][2];
					res[tot][2]=res[tot][3];
					res[tot][3]=res[tot][4];
				}
				solve(tot);
				flag=0;
				break;
			}
		}
		if(flag)break;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		printf("%d ",res[i][0]);
		for(int j=1;j<=res[i][0];j++)printf("%d ",res[i][j]);
		printf("\n");
	}
	return 0;
}