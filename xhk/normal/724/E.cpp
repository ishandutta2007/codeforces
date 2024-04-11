#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n,lim;
int a[10010],b[10010];
long long ans;
long long f[2][10010];

inline void update(long long &i,long long x)
{i=(i==-1 || x<i)?x:i;
}

int main()
{int i,j,i1,x;
 long long s1=0;
 
 scanf("%d%d",&n,&lim);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 for(i=1;i<=n;i++) scanf("%d",&b[i]);
 for(i=1;i<=n;i++)
 {	x=min(a[i],b[i]);
 	a[i]-=x;
 	b[i]-=x;
 	s1+=x;
 }
 memset(f,-1,sizeof(f));
 f[0][0]=0;
 x=0;
 for(i=0;i<n;i++)
 {	i1=i&1;
 	/*
 	cout<<i<<" "<<x<<endl;
 	for(j=0;j<=n;j++) cout<<f[i1][j]<<" ";
 	cout<<endl;
	*/
	for(j=0;j<=i;j++)
 	{	if(f[i1][j]==-1) continue;
 		//cout<<f[0][0]<<" "<<b[i+1]<<" "<<x-j<<" "<<lim<<" "<<min((ll)b[i+1],(ll)(x-j)*lim)<<" "<<s<<endl;
 		if(b[i+1]>0)
		{ 	//update(f[i1^1][j],f[i1][j]+min((ll)b[i+1],(ll)(x-j)*lim));
			update(f[i1^1][j],f[i1][j]+b[i+1]);
			update(f[i1^1][j+1],f[i1][j]+(ll)(x-j)*lim);
		}
 		else if(a[i+1]>0)
 		{	update(f[i1^1][j],f[i1][j]);
		 	update(f[i1^1][j+1],f[i1][j]+a[i+1]+(ll)(x-j)*lim);
		}
		else
			f[i1^1][j]=f[i1][j];
	}
	if(a[i+1]>0 || b[i+1]>0) x++;
	for(j=0;j<=n;j++) f[i1][j]=-1;
 }
 ans=-1;
 for(i=0;i<=x;i++)
 	update(ans,f[n&1][i]);
 ans+=s1;	
 printf("%I64d\n",ans);
 return 0;
}