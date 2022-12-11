#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j,k=0;
    cin>>t;
    while(t--)
    {
        long long rz=0,a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>=a)
        {
            cout<<a<<'\n';
            continue;
        }
        if(b*1LL*c<a)
        {
            cout<<-1<<'\n';
            continue;
        }
        long long nrmx=(a-1LL)/b;
        nrmx=nrmx-nrmx%d;
        long long nrad=nrmx/d+1;
        rz=nrad*1LL*a;
        --nrad;
        nrad=nrad*1LL*(nrad+1LL)/2LL;
        nrad=nrad*1LL*d*1LL*b;
        cout<<rz-nrad<<'\n';
    }
    return 0;
}