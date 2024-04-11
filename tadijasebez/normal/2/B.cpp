#include <stdio.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
#define pb push_back
const int inf=1e9+7;
const int N=1050;
int dp2[N][N],dp5[N][N],a[N][N],b[N][N];
char sol[2*N];
int min(int a, int b){ return a>b?b:a;}
void PrintPath2(int i, int j)
{
	if(clock()>=1.5*CLOCKS_PER_SEC){ printf("???");exit(0);}
	if(i==1 && j==1) return;
	if(dp2[i][j]==dp2[i-1][j]+a[i][j])
	{
		PrintPath2(i-1,j);
		printf("D");
	}
	else
	{
		PrintPath2(i,j-1);
		printf("R");
	}
}
void PrintPath5(int i, int j)
{
	if(clock()>=1.5*CLOCKS_PER_SEC){ printf("???");exit(0);}
	if(i==1 && j==1) return;
	if(dp5[i][j]==dp5[i-1][j]+b[i][j])
	{
		PrintPath5(i-1,j);
		printf("D");
	}
	else
	{
		PrintPath5(i,j-1);
		printf("R");
	}
}
int main()
{
	int n,i,j,x,X,Y;
	scanf("%i",&n);
	bool zero=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%i",&x);
			if(!x) a[i][j]=1,b[i][j]=1,zero=1,X=i,Y=j;
			else
			{
				while((x&1)==0) a[i][j]++,x>>=1;
				while((x-x/5*5)==0) b[i][j]++,x/=5;
			}
		}
	}
	for(i=0;i<N;i++) for(j=0;j<N;j++) dp2[i][j]=dp5[i][j]=inf;
	//dp2[0][1]=dp5[0][1]=0;
	dp2[1][1]=a[1][1];
	dp5[1][1]=b[1][1];
	for(i=2;i<=n;i++)
	{
		dp2[1][i]=dp2[1][i-1]+a[1][i];
		dp2[i][1]=dp2[i-1][1]+a[i][1];
		dp5[1][i]=dp5[1][i-1]+b[1][i];
		dp5[i][1]=dp5[i-1][1]+b[i][1];
	}
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=n;j++)
		{
			dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+a[i][j];
			dp5[i][j]=min(dp5[i-1][j],dp5[i][j-1])+b[i][j];
		}
	}
	if(zero)
	{
		if(dp2[n][n] && dp5[n][n])
		{
			printf("1\n");
			for(i=2;i<=X;i++) printf("D");
			for(i=2;i<=n;i++) printf("R");
			for(i=X+1;i<=n;i++) printf("D");
			return 0;
		}
	}
	printf("%i\n",min(dp2[n][n],dp5[n][n]));
	if(dp2[n][n]<dp5[n][n])
	{
		PrintPath2(n,n);
		/*i=n;j=n;
		while(i!=1 || j!=1)
		{
			if(i<1 || j<1) return printf("???\n"),0;
			if(dp2[i-1][j]==dp2[i][j]-a[i][j]) sol[i+j]='D',i--;
			else sol[i+j]='R',j--;
		}
		//reverse(sol.begin(),sol.end());
		for(i=3;i<=2*n;i++) printf("%c",sol[i]);*/
	}
	else
	{
		PrintPath5(n,n);
		/*i=n;j=n;
		while(i!=1 || j!=1)
		{
			if(i<1 || j<1) return printf("???\n"),0;
			//printf("%i %i\n",i,j);
			if(dp5[i-1][j]==dp5[i][j]-b[i][j]) sol[i+j]='D',i--;
			else sol[i+j]='R',j--;
		}
		//reverse(sol.begin(),sol.end());
		for(i=3;i<=2*n;i++) printf("%c",sol[i]);*/
	}
	return 0;
}