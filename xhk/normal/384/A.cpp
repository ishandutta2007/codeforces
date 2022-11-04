#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,ans=0;

int main()
{int i,j;
 cin>>n;
 
 if(n%2==0)
   printf("%d\n",n*n/2);
 else
   printf("%d\n",(n+1)*(n/2)+1);  
 
 for(i=1;i<=n;i++)
 {for(j=1;j<=n;j++)
    if((i%2)==(j%2))
     printf("C");
    else
     printf(".");
  printf("\n");
 }
 
 return 0;
}