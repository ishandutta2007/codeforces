#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b>>n;
        if(max(a,b)>n)
        {
            cout<<0<<'\n';
            continue;
        }
        if(a+b>n)
        {
            cout<<1<<'\n';
            continue;
        }
        int cnt=0;
        while(a<=n && b<=n)
        {
            if(a<b)
                swap(a,b);
            b+=a;
            ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}