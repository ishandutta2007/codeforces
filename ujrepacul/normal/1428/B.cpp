#include <bits/stdc++.h>
using namespace std;
char v[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        v[0]=v[n];
        int ok1=0,ok2=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]=='>')
                ok1=1;
            if(v[i]=='<')
                ok2=1;
        }
        if(ok1*ok2==0)
        {
            cout<<n<<'\n';
            continue;
        }
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]=='-' || v[i-1]=='-')
                ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}