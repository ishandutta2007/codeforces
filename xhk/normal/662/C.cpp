#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,ans;
int cnt[1100010];
long long f[11000010],g[1100010];
char a[21][100010];

void fwt(long long A[],int N)
{int i,j,p;
 long long x,y;
 
 for(i=0;i<N;i++)
 	for(j=0;j<(1<<N);j++)
 	{	if(j&(1<<i)) continue;
 		p=j^(1<<i);
 		x=A[j];
 		y=A[p];
 		A[j]=x+y;
 		A[p]=x-y;
	}
}
 		
int main()
{int i,j,k,i0,i1,i2,s;
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 	scanf("%s",a[i]+1);
 for(i=1;i<=m;i++)
 {	s=0;
 	for(j=1;j<=n;j++)
	 	s=s*2+(a[j][i]=='1');
	f[s]++;
 }
 for(i=1;i<(1<<n);i++) cnt[i]=cnt[i-(i&(-i))]+1;
 for(i=0;i<(1<<n);i++)
 	g[i]=min(cnt[i],n-cnt[i]);
 fwt(f,n);
 fwt(g,n);
 for(i=0;i<(1<<n);i++) f[i]=f[i]*g[i];
 fwt(f,n);
 for(i=0;i<(1<<n);i++) f[i]/=(1<<n);
 ans=n*m+1;
 for(i=0;i<(1<<n);i++)
 	ans=min(ans,(int)f[i]);
 printf("%d\n",ans);
 return 0;
}