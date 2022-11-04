#include<bits/stdc++.h>
using namespace std;

int n,m,l,r,ans;
int a[110][110],b[110];

int calc(int k,int i,int j)
{int p,ret;

 for(p=1;p<=m;p++)
	b[p]=a[k][p];
 swap(b[i],b[j]);
 swap(b[l],b[r]);
 ret=1;
 for(p=1;p<=m;p++)
 	if(b[p]!=p)
 	{	ret=0;
 		break;
 	}
 if(ret) return 1;	
 for(p=1;p<=m;p++)
 	b[p]=a[k][p];
 swap(b[l],b[r]);
 swap(b[i],b[j]);
 ret=1;
 for(p=1;p<=m;p++)
 	if(b[p]!=p)
 	{	ret=0;
 		break;
 	}
 return ret;
}

int check()
{int ret=1,k,i,j,s;
 
 for(k=1;k<=n;k++)
 {	ret=0;
 	ret=calc(k,0,0);
 	for(i=1;i<=m;i++)
 		for(j=i+1;j<=m;j++)
 			if(calc(k,i,j)) ret=1;
	if(!ret) return 0;
 }
 return 1;
}

int main()
{int i,j;
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 	for(j=1;j<=m;j++)
 		scanf("%d",&a[i][j]);
 for(i=1;i<=m;i++) b[i]=i;
 l=0;
 r=0;
 if(check()) ans=1;
 for(i=1;i<=m;i++)
 	for(j=i+1;j<=m;j++)
	{	//swap(b[i],b[j]);
		l=i;
		r=j;
		if(check()) ans=1;
		//swap(b[i],b[j]);
		if(ans) break;	
	}
 if(ans)
 	printf("YES\n");	
 else
 	printf("NO\n");
 return 0;
}