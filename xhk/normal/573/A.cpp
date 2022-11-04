#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a[100010];

int gcd(int i,int j)
{if(j==0) return i;
 return gcd(j,i%j);
}

int check(int x,int y)
{int k;
 
 k=gcd(x,y);
 x/=k;
 y/=k;
 while(x%2==0) x/=2;
 while(x%3==0) x/=3;
 if(x!=1) return 0;
 
 while(y%2==0) y/=2;
 while(y%3==0) y/=3;
 if(y!=1) return 0;
 
 return 1;
}

int main()
{int i,j,flag;
 
 scanf("%d",&n);
 
 for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
 flag=1;    
 for(i=2;i<=n;i++)
    if(!check(a[1],a[i]))
        flag=0; 

 if(flag==1)
    printf("Yes\n");
 else
    printf("No\n");
 
 return 0;
}