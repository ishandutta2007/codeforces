#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct unit 
{int num,p;
};
struct unit a[300010];

bool cmp(struct unit aa,struct unit bb)
{return aa.num<bb.num;
}

int n,b[300010];

int main()
{int i,j,min1=-1,s=0;
 
 cin>>n;
 
 for(i=1;i<=n;i++)
 {cin>>a[i].num;
  a[i].p=i;
  if(a[i].num<min1 || min1==-1) min1=a[i].num;
 }
 
 sort(a+1,a+n+1,cmp);
 
 for(i=1;i<=n;i++)
 {if(a[i].num>s)
  {b[a[i].p]=a[i].num;
   s=a[i].num;
  }
  else
  {b[a[i].p]=s+1;
   s++;
  }
 }
 
 for(i=1;i<=n;i++)
 {if(i!=1) printf(" "); 
  printf("%d",b[i]);
 }
 
 return 0;
}