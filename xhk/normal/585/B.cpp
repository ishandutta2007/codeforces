#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,k,nq,ans;
int f[10][110];
char a[10][110];

int main()
{int i,j,q;
 
 scanf("%d",&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%d%d",&n,&k);
 
 	scanf("%s",a[1]+1);
 	scanf("%s",a[2]+1);
 	scanf("%s",a[3]+1);
 	a[1][n+1]='.';
 	a[2][n+1]='.';
 	a[3][n+1]='.';
 	a[1][n+2]='.';
 	a[2][n+2]='.';
 	a[3][n+2]='.';
 	a[1][n+3]='.';
 	a[2][n+3]='.';
 	a[3][n+3]='.';
 
 	memset(f,0,sizeof(f));
	for(i=1;i<=3;i++)
 	{	for(j=1;j<=n;j++)
 			if(a[i][j]=='s')
 			{	f[i][j]=1;
 				break;
 			}
 	}
 	
 	for(j=1;j<=n;j++)
 		for(i=1;i<=3;i++)
 			if(a[i][j]=='.' || a[i][j]=='s')
 			{	if(f[i][j]==1)
 				{	if(a[i][j+1]=='.' && a[i-1][j+1]=='.' && a[i-1][j+2]=='.' && a[i-1][j+3]=='.')
				 		f[i-1][j+3]=1;
					if(a[i][j+1]=='.' && a[i][j+2]=='.' && a[i][j+3]=='.')
						f[i][j+3]=1;
					if(a[i][j+1]=='.' && a[i+1][j+1]=='.' && a[i+1][j+3]=='.' && a[i+1][j+3]=='.')
						f[i+1][j+3]=1;
				}
			}
 	/*
 	for(i=1;i<=3;i++)
 	{	for(j=1;j<=n+1;j++)
 			cout<<f[i][j]<<" ";
 		cout<<endl;	
  	}
 	*/
 	ans=0;
	if(f[1][n+1]==1 || f[2][n+1]==1 || f[3][n+1]==1)
 		ans=1;
 	if(f[1][n+2]==1 || f[2][n+2]==1 || f[3][n+2]==1)
 		ans=1;
	if(f[1][n+3]==1 || f[2][n+3]==1 || f[3][n+3]==1)
 		ans=1;	
 		
 	if(ans==1)
	 	printf("YES\n");
	else
		printf("NO\n");
 }
 
 return 0;
}