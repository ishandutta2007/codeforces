#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int n,k,ans;
int a[200010];
map<int,int> f;

int calc(int i)
{int j,x1,x2;
 
 if(f[i]) return f[i]-1;
 if(i==0) return 0;
 
 if(k%2==0)
 {  if(i%2==0)
        f[i]=1;
    else
        f[i]=0; 
 }
 else
 {  if(i%2==1)
        f[i]=0;
    else
    {   x1=calc(i/2);
        if(x1==1)
            f[i]=2;
        else
            f[i]=1;
    }
 }
 f[i]++;
 return f[i]-1;
}

int main()
{int i,j,x1,x2;
 
 f[1]=2;
 
 scanf("%d%d",&n,&k);
 
 if(k%2==1)
 {  f[2]=1;
    f[3]=2;
    f[4]=3;
 }
 else
 {  f[2]=3;
    f[3]=1;
    f[4]=2;
 }
 
 for(i=1;i<=n;i++)
 {  scanf("%d",&a[i]);
    ans^=calc(a[i]);
 }

 if(ans!=0)
    printf("Kevin\n");
 else
    printf("Nicky\n");
 
 return 0;
}