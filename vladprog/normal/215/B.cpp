#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

int main()
{
    int n;
    cin>>n;
    int xm=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        xm=max(xm,x);
    }
    int m;
    cin>>m;
    int y[m];
    for(int i=0;i<m;i++)
        cin>>y[i];
    int k;
    cin>>k;
    int z[k];
    for(int i=0;i<k;i++)
        cin>>z[i];
    int a,b;
    cin>>a>>b;
    ld r2=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<k;j++)
            r2=max(r2,sqrt(ld(xm)*xm*y[i]/z[j]/(ld(a)/b+ld(y[i])/z[j])));
    cout<<setprecision(9)<<r2;
}