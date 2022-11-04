#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct unit
{int v,d,p;
};
struct unit a[5010];

int n,ans;
int b[5010],used[5010];

int main()
{int i,j,k,v;

 scanf("%d",&n);
 
 for(i=1;i<=n;i++)
 	scanf("%d%d%d",&a[i].v,&a[i].d,&a[i].p);
 
 for(i=1;i<=n;i++)
 {	if(a[i].p<0) continue;
 	ans++;
 	b[ans]=i;
	v=a[i].v;
 	for(j=i+1;j<=n;j++)
 	{	if(a[j].p>=0)
 		{	a[j].p-=v;
 			v--;
 		}
 		if(v<=0)
 			break;
 	}
	for(j=i+1;j<=n;j++)
	 	if(a[j].p<0 && used[j]==0)
		{	used[j]=1;
			for(k=j+1;k<=n;k++)
				if(a[k].p>=0)
					a[k].p-=a[j].d;
		}
 }
  
 printf("%d\n",ans);
 
 for(i=1;i<=ans;i++)
 {	printf("%d",b[i]); 
 	if(i!=ans)
 		printf(" ");
 	else
	 	printf("\n");
 }
 
 return 0;
}