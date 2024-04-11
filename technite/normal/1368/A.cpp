//template start//
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
int main()
{
    fast;
    TT
    {
        int a,b,n;
        cin>>a>>b>>n;
        int count=0;
        if(a>=b) swap(a,b);
        bool c=true;
        while(a<=n&&b<=n)
        {
            if(c) {a+=b;c=false;}
            else {b+=a;c=true;}
            count++;
        }
        cout<<count<<'\n';
    }
}