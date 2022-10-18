#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,d1,d2;
        cin>>n>>k>>d1>>d2;
        if(d1>d2)
            swap(d1,d2);
        bool ok=false;
        #define check(x,y) if((k>=(x)&&(k-(x))%3==0)&&(n-k>=(y)&&(n-k-(y))%3==0)) ok=true
        check( d1+d2, 2*d2-d1 );
        check( 2*d1+d2, 2*d2+d1 );
        check( 2*d2+d1, 2*d1+d2 );
        check( 2*d2-d1, d1+d2 );
        cout<<(ok?"yes":"no")<<"\n";
    }
}