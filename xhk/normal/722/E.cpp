#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod=1000000007;

struct unit
{int x,y,flag;
};
struct unit a[2010];

int n,m,nt,ans;
int fac[200010],ifac[200010],g[2010][22];

bool operator <(unit A,unit B)
{return A.x<B.x || (A.x==B.x && A.y<B.y) || (A.x==B.x && A.y==B.y && A.flag<B.flag);
}

int fpow(int i,int j)
{int ret=1;
 for(;j;i=(ll)i*i%mod,j/=2)
 	if(j&1) ret=(ll)ret*i%mod;
 return ret;
}

int comb(int N,int M)
{return (ll)fac[N]*ifac[M]%mod*ifac[N-M]%mod;
}

int main()
{int i,j,k,flag2=0,s;
 
 scanf("%d%d%d%d",&n,&m,&nt,&s);
 fac[0]=1;
 for(i=1;i<=n+m;i++) fac[i]=(ll)fac[i-1]*i%mod;
 ifac[n+m]=fpow(fac[n+m],mod-2);
 for(i=n+m-1;i>=0;i--) ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
 for(i=1;i<=nt;i++)
 {	scanf("%d%d",&a[i].x,&a[i].y);
 	a[i].flag=1;
 	if(a[i].x==n && a[i].y==m) flag2=1;
 }
 a[++nt]=(unit){1,1,0};
 if(!flag2) a[++nt]=(unit){n,m,0};
 sort(a+1,a+nt+1);
 g[1][a[1].flag]=1;
 for(i=2;i<=nt;i++)
 	for(k=0;k<=21;k++)
 	{	for(j=1;j<i;j++)
			if(a[j].x<=a[i].x && a[j].y<=a[i].y)
 			{	if(k>=a[i].flag) g[i][k]=(g[i][k]+(ll)g[j][k-a[i].flag]*comb(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x)%mod)%mod;
 				//if(i==nt) cout<<i<<" "<<j<<" "<<k<<" "<<g[i][k]<<" "<<g[j][k-a[i].flag]<<" ## "<<g[4][0]<<endl;
			}
		if(k>a[i].flag) g[i][k-1]=(g[i][k-1]-g[i][k]+mod)%mod;
	}
 /*
 for(i=1;i<=nt;i++)
 {	for(j=0;j<=4;j++)
 		cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
 }
 */
 for(i=0;i<=21;i++)
 {	ans=(ans+(ll)g[nt][i]*s%mod)%mod;
 	s=(s+1)/2;
 }
 ans=(ll)ans*fpow(comb(n+m-2,n-1),mod-2)%mod;
 printf("%d\n",ans);
 return 0;
}