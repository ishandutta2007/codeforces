#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int ans;
long long x,y;
long long f[1000010][2];

int main()
{int i,j,flag=1;
 
 scanf("%I64d%I64d",&x,&y);
 
 x--;
 y--;
 while(flag)
 {	if(x>y)
 	{	ans++;
 		f[ans][0]=1;
 		f[ans][1]=x/(y+1);
	 	x=x%(y+1);
	}
	else if(y>x)
	{	ans++;
		f[ans][0]=2;
		f[ans][1]=y/(x+1);
		y=y%(x+1);
	}
	else
	{	if(x!=0)
		{	printf("Impossible\n");
			return 0;
		}
		flag=0;
	}
 }
 
 for(i=1;i<=ans;i++)
 {	printf("%I64d",f[i][1]);
 	if(f[i][0]==1)
 		printf("A");
 	else
	 	printf("B");
 }
 
 return 0;
}