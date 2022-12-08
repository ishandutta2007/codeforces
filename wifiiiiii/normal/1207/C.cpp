#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        int f1=-1,r1=-1;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='1')
            {
                if(f1==-1) f1=i;
                r1=i;
            }
        }
        if(f1==-1) {cout<<a*n+b*(n+1)<<endl;continue;}
        if(f1==r1)
        {
            cout<<a*(n+2)+b*(n+3)<<endl;
            continue;
        }
        ll ans=(n+2)*a+(f1+n-1-r1)*b+(r1-f1+2)*2*b;
        int lst=f1;
        for(int i=f1+1;i<=r1;++i)
        {
            if(s[i]=='1')
            {
                if(i-lst>2)
                {
                    ll k=i-lst-1;
                    if(b*(k-1)-2*a>=0) ans -= b*(k-1)-2*a;
                }
                lst=i;
            }
        }
        cout<<ans<<endl;
    }
}