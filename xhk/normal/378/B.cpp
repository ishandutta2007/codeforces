#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct unit
{int f,r,num;
};
struct unit c[200010];

int n,a[100010],b[100010],a1[100010],b1[100010];;

bool cmp(struct unit aa,struct unit bb)
{return aa.num<bb.num;
}

int main()
{int i,j;
 
 scanf("%d",&n);
 
 for(i=1;i<=n;i++) 
 {scanf("%d%d",&a[i],&b[i]);
  if(i<=n/2) 
  {a1[i]=1; 
   b1[i]=1;
  }
  c[i*2-1].f=1;
  c[i*2-1].r=i;
  c[i*2-1].num=a[i];
  c[i*2].f=2;
  c[i*2].r=i;
  c[i*2].num=b[i];
 }
 
 sort(c+1,c+2*n+1,cmp);
 
 for(i=1;i<=n;i++)
 {if(c[i].f==1)
    a1[c[i].r]=1;
  else 
    b1[c[i].r]=1;
 }
 
 for(i=1;i<=n;i++) printf("%d",a1[i]);
 printf("\n");
 for(i=1;i<=n;i++) printf("%d",b1[i]);
 printf("\n");
 
 return 0;
}