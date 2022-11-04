#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,x,m,tot,s;
int a[30],b[100010],c[100010];

int gcd(int i,int j)
{if(j==0) return i;
 return gcd(j,i%j);
}

int main()
{int i,j,k,flag,f1; 

 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {  scanf("%d",&a[i]);
    if(x!=0) 
        x=gcd(x,a[i]);  
    else
        x=a[i];
    m+=a[i];    
 }
 
 flag=0;
 for(j=1;j<=n;j++)
    if((a[j]/x)&1)
        flag++;     
 f1=1;              
 if(flag>=2)
 {  if(x%2==0)
    {   x/=2;
        f1=2;
    }
    else
    {   printf("%d\n",0);
        for(i=1;i<=n;i++)
            for(j=1;j<=a[i];j++)
                printf("%c",i+96);
        printf("\n");
        return 0;
    }
 }
 else if(flag==0)
    f1=2;   

 flag=0;
 for(j=1;j<=n;j++)
 {  for(k=1;k<=a[j]/x;k++)
    {   tot++;
        b[tot]=96+j;
    }
    if((a[j]/x)%2!=0)
    {   s++;
        flag=j;
    }
 }  

 j=1;
 k=tot;
 for(i=1;i<=tot;i++)
 {  if(b[i]==96+flag) continue;
    if(i&1)
    {   c[j]=b[i];
        j++;
    }
    else
    {   c[k]=b[i];
        k--;
    }
 } 
 //for(i=1;i<=tot;i++)
 // printf("%c ",c[i]);
 
 for(i=j;i<=k;i++)
    c[i]=96+flag;
 flag=1;
 for(i=1;i<=tot/2;i++)
    if(c[i]!=c[tot+1-i])
    {   flag=0;
        break;
    }
 printf("%d\n",x*f1);
 for(i=1;i<=x;i++)
    for(j=1;j<=tot;j++)
        printf("%c",c[j]);
 printf("\n");
 return 0;
}