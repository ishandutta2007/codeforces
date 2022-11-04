#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

int n,nq;
int a[100010],b[100010],q[100010],c1[100010],c2[100010];
long long ans;

int main()
{int i,j,w,x,y,l,r;
 
 scanf("%d%d",&n,&nq);
 
 for(i=1;i<=n;i++)
 	scanf("%d",&b[i]);
 
 for(i=1;i<n;i++)
 	a[i]=fabs(b[i+1]-b[i]);
 
 n--;
 
 for(i=1;i<=n;i++)
 	c1[i]=n+1;
 
 w=0;
 for(i=1;i<=n;i++)
 {	while(w>0 && a[i]>a[q[w]])
 	{	c1[q[w]]=i;
 		w--;
 	}
 	w++;
 	q[w]=i;
 }
 
 w=0;
 for(i=n;i>=1;i--)
 {	while(w>0 && a[i]>=a[q[w]])
 	{	c2[q[w]]=i;
	 	w--;
	}
	w++;
	q[w]=i;
 }
 
 //for(i=1;i<=n;i++)
 //	cout<<c1[i]<<" "<<c2[i]<<endl;
 
 for(j=1;j<=nq;j++)
 {	scanf("%d%d",&x,&y);
 	ans=0;
 	for(i=x;i<y;i++)
 	{	l=max(x,c2[i]+1);
	 	r=min(y-1,c1[i]-1);
		ans+=(long long)a[i]*(i-l+1)*(r-i+1);
 	}
 	cout<<ans<<endl;
 }
 
 return 0;
}