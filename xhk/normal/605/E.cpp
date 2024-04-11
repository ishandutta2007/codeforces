#include<cstdio>
using namespace std;

int n;
int used[1010];
double inf=1e18;
double ga[1010][1010],a[1010],f[1010],f1[1010],fp[1010];

int main()
{int i,j,k,x;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {	for(j=1;j<=n;j++)
 	{	scanf("%d",&x);
 		ga[i][j]=0.01*x;
	}
	ga[i][i]=1;
 	f[i]=inf;
	fp[i]=1;
	f1[i]=1;
 }
 f[n]=0;
 for(i=1;i<=n;i++)
 {	k=0;
 	for(j=1;j<=n;j++)
 		if(used[j]==0 && (k==0 || f[j]<f[k]))
 			k=j;
 	//printf("%d %d\n",i,k);
 	used[k]=1;	
	for(j=1;j<=n;j++)
		if(used[j]==0)
		{	f1[j]+=fp[j]*ga[j][k]*f[k];
			fp[j]*=(1-ga[j][k]);
			f[j]=f1[j]/(1-fp[j]);
			//printf("%d %.4lf %.4lf\n",j,f1[j],f[j]);
		}
 }
 printf("%.10lf\n",f[1]);
 return 0;
}