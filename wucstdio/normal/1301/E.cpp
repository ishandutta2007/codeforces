#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,q,sum[505][505],maxs[505][505],st[12][12][505][505],lg2[505];
char s[505][505];
bool check(char c,int l1,int l2,int r1,int r2)
{
	if(l1<1||l2<1||l1>n||l2>m)return 0;
	return s[l1][l2]==c&&sum[r1][r2]-sum[l1][r2]-sum[r1][l2]+sum[l1][l2]==0;
}
int ask(int l1,int l2,int r1,int r2)
{
	int i=lg2[r1-l1+1],j=lg2[r2-l2+1];
	int ans=max(max(st[i][j][l1][l2],st[i][j][r1-(1<<i)+1][l2]),max(st[i][j][l1][r2-(1<<j)+1],st[i][j][r1-(1<<i)+1][r2-(1<<j)+1]));
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			sum[i][j]+=((s[i][j]!=s[i-1][j])||(s[i][j]!=s[i][j-1]));
		}
	}
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)
	{
		int len=1;
		while(check('R',i-len+1,j-len+1,i,j)&&check('G',i-len+1,j+1,i,j+len)&&check('Y',i+1,j-len+1,i+len,j)&&check('B',i+1,j+1,i+len,j+len))len++;
		maxs[i][j]=len-1;
	}
	for(int i=2;i<=max(n,m);i++)lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<n;i++)
	  for(int j=1;j<m;j++)
	    st[0][0][i][j]=maxs[i][j];
	for(int i=0;i<=lg2[n];i++)
	for(int j=0;j<=lg2[m];j++)
	{
		if(i==0&&j==0)continue;
		for(int x=1;x+(1<<i)-1<n;x++)
		for(int y=1;y+(1<<j)-1<m;y++)
		{
			if(i)st[i][j][x][y]=max(st[i-1][j][x][y],st[i-1][j][x+(1<<(i-1))][y]);
			else st[i][j][x][y]=max(st[i][j-1][x][y],st[i][j-1][x][y+(1<<(j-1))]);
		}
	}
	while(q--)
	{
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&l2,&r1,&r2);
		int l=1,r=min(r1-l1,r2-l2);
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(mid*2>r1-l1+1||mid*2>r2-l2+1)r=mid-1;
			else
			{
				int ll1=l1+mid-1,ll2=l2+mid-1,rr1=r1-mid,rr2=r2-mid;
				if(ask(ll1,ll2,rr1,rr2)>=mid)l=mid+1;
				else r=mid-1;
			}
		}
		printf("%d\n",r*r*4);
	}
	return 0;
}