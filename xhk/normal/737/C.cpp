#include<bits/stdc++.h>
using namespace std;

int n,id,ans,tot;
int a[200010],b[200010];

int main()
{int i,j,k,t,w;
 
 scanf("%d%d",&n,&id);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 if(a[id]!=0) ans++;
 k=0;
 for(i=1;i<=n;i++)
 	if(i!=id && a[i]==0)
 	{	ans++;
 		k++;
 	}
 	else if(i!=id)
 		b[++tot]=a[i];
 sort(b+1,b+tot+1);
 t=1;
 w=tot;
 for(i=1;i<=n;i++)
 	if(t<=w && b[t]==i)
 	{	while(t<=w && b[t]==i) t++;
 	}
 	else if(t<=w)
 	{	if(k>0)
	 		k--;
 		else
	 	{	w--;
 			ans++;
 		}
 	}
 printf("%d\n",ans);
 return 0;
}