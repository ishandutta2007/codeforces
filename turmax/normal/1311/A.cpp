#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }
        if(a<b && (b-a)%2==1)
        {
            cout<<1<<endl;
        }
        else if(a>b && (a-b)%2==0)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<2<<endl;
        }
    }
    return 0;
}