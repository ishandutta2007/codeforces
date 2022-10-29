#include<iostream>
#include<cstdio>

using namespace std;

const int inf=100000000;
int f0[100],f1[100],f2[100],f[100][4],F0[100][100][100],F1[100][100][100],F2[100][100][100];
int n;
char S[100];
int main()
{
	scanf("%d",&n);
	scanf("%s",S);
	int a0=0,a1=0,a2=0;
	for (int i=0;i<n;i++)
	{
		if (S[i]=='V') 
		{
			a0++;
			f0[a0]=i;
		}
		else if (S[i]=='K') 
		{
			a1++;
			f1[a1]=i;
		}
		else 
		{
			a2++;
			f2[a2]=i;
		}
		f[i][0]=a0;
		f[i][1]=a1;
		f[i][2]=a2;	
	}
	for (int i=0;i<=a0;i++)
	for (int j=0;j<=a1;j++)
	for (int k=0;k<=a2;k++)
	{
		if (!i&&!j&&!k) 
		{
			continue;	
		}
		if (i==0) F0[i][j][k]=inf;
		else 
		{
			int K=f0[i];
			F0[i][j][k]=F0[i-1][j][k]+max(f[K][1]-j,0)+max(f[K][2]-k,0);
			F0[i][j][k]=min(F0[i][j][k],F1[i-1][j][k]+max(f[K][1]-j,0)+max(f[K][2]-k,0));
			F0[i][j][k]=min(F0[i][j][k],F2[i-1][j][k]+max(f[K][1]-j,0)+max(f[K][2]-k,0));
		}
		if (j==0) F1[i][j][k]=inf;
		else 
		{
			int K=f1[j];
			F1[i][j][k]=F1[i][j-1][k]+max(f[K][0]-i,0)+max(f[K][2]-k,0);
			F1[i][j][k]=min(F1[i][j][k],F2[i][j-1][k]+max(f[K][0]-i,0)+max(f[K][2]-k,0));
		}
		if (k==0) F2[i][j][k]=inf;
		else 
		{
			int K=f2[k];
			F2[i][j][k]=F0[i][j][k-1]+max(f[K][0]-i,0)+max(f[K][1]-j,0);
			F2[i][j][k]=min(F2[i][j][k],F1[i][j][k-1]+max(f[K][0]-i,0)+max(f[K][1]-j,0));
			F2[i][j][k]=min(F2[i][j][k],F2[i][j][k-1]+max(f[K][0]-i,0)+max(f[K][1]-j,0));
		}
	}
	int ans=min(min(F0[a0][a1][a2],F1[a0][a1][a2]),F2[a0][a1][a2]);
	printf("%d\n",ans);
	return 0;
}