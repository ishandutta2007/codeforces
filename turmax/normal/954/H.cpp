#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=5e3+5;
int32_t z[maxn+1][2*maxn+1];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    n--;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int ans[2*n+1];
    for(int i=0;i<(2*n+1);++i) ans[i]=0;
    //(path(>=1)-depth+n)
    for(int i=0;i<=n;++i)
    {
        //cout<<z[i][7]<<" z[i][7] "<<endl;
        for(int j=0;j<=(2*n+1);++j) {z[i+1][j]=z[i][j];}
        int pr=1;
        for(int j=(n-i);j<=(2*(n-i));++j)
        {
            //cout<<i<<" i "<<j<<" j "<<pr<<" pr "<<endl;
            z[i+1][j+1]+=pr;
            z[i+1][j+1]%=p;
            if((j!=(2*n-2*i)) && j!=(n-i)) {pr*=a[j-(n-i)+i];pr%=p;}
            else if(j==(n-i)) {pr*=(a[j-(n-i)+i]-1);pr%=p;}
        }
    }
    //for(int i=0;i<=n;++i) for(int j=0;j<=2*n+1;++j) cout<<z[i][j]<<' ';
    //cout<<endl;
    for(int i=n;i>=0;i--)
    {
        int o=1;
        for(int j=0;j<i;++j) {o*=a[j];o%=p;}
        //cout<<o<<" o "<<endl;
        int pr=1;
        for(int j=0;j<=(n-i);++j)
        {
            //cout<<pr<<" pr "<<endl;
            ans[j]+=((pr*o)%p);ans[j]%=p;
            if((i+j)!=n) {pr*=a[i+j];pr%=p;}
        }
        if(i==0) continue;
        for(int j=0;j<=(i+n);++j)
        {
            ans[j]+=((o*((int) z[i][j-i+n+1]))%p);
            //cout<<i<<" i "<<j<<" j "<<z[i][j-i+n-1]<<" z "<<endl;
            ans[j]%=p;
        }
    }
    for(int i=1;i<=2*n;++i) cout<<((ans[i]*(p+1)/2)%p)<<' ';
    return 0;
}