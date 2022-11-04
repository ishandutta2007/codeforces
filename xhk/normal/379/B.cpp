#include<cstdio>
#include<iostream>
using namespace std;

int n,a[1000];

int main()
{int i,j,f,s=0,p=0;
 
 scanf("%d",&n);
 
 for(i=1;i<=n;i++) 
 {scanf("%d",&a[i]);
  s=s+a[i];
 }
 
 p=1;
 f=0;
 while(s>0)
 {if(a[p]>0)
  {printf("P");
   a[p]--;
   s--;
  }
  
  if(s==0) break;
  
  if(f==0)
  {p++;
   printf("R");
  }
  else if(f==1)
  {p--;
   printf("L");
  }
  
  if(p==n) f=1;
  if(p==1) f=0;
 }
 
 printf("\n");
 return 0;
}