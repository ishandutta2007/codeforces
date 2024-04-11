#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500500;
ll mod=1e9+7;
int n,l,r;
ll a[10];
ll f[maxn][3];
int main()
{
    scanf("%d%d%d",&n,&l,&r);
    int len=(r-l+1)/3;
    for(int i=0;i<=2;i++)a[i]+=(ll)len;
    for(int i=l+len*3;i<=r;i++)a[i%3]++;
    //for(int i=0;i<=2;i++)printf("%d  ",a[i]);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
	    for(int j=0;j<=2;j++)
	    {
		    for(int k=0;k<=2;k++)
		    {
			    f[i][j]=(f[i][j]+a[k]*f[i-1][(j-k+3)%3])%mod;
		    }
	    }
    }cout<<f[n][0]<<endl;
}