#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
ll a[5005],f[5005][5005];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=k;j++)
		{
            int xx=lower_bound(a+1,a+i+1,a[i]-5)-a;
            f[i][j]=max(f[i-1][j],f[xx-1][j-1]+(i-xx+1));
        }
    }
    cout<<f[n][k]<<endl;
    return 0;
}