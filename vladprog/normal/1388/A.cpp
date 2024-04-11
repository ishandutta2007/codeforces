#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a=6,b=10,c=14,d=n-a-b-c;
        if(d==a||d==b||d==c)
            c++,
            d--;
        if(d>=1)
            cout<<"YES\n"<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
        else
            cout<<"NO\n";
    }
}