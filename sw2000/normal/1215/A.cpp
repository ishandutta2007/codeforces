#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4000;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int main()
{
    int a,b,c,d;
    int n,nn;
    int mi,ma;
    cin>>a>>b>>c>>d;
    cin>>n;
    nn=n;
    n-=a*(c-1);
    n-=b*(d-1);
    if(n<=0)mi=0;
    else mi=n;

    if(c<d)
    {
        if(nn<c*a)
        {
            ma=nn/c;
        }
        else
        {
            ma=a;
            ma+=(nn-c*a)/d;
        }
    }
    else
    {
        if(nn<b*d)
        {
            ma=nn/d;
        }
        else
        {
            ma=b;
            ma+=(nn-b*d)/c;
        }
    }
    cout<<mi<<' '<<ma;
    return 0;
}