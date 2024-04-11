#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int d=0,s=0;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a&1)d++;
            else s++;
        }
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a&1)ans+=d;
            else ans+=s;
        }
        cout<<ans<<endl;
    }
    return 0;
}