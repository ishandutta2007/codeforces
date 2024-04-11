#include<bits/stdc++.h>

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
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        if(a1>b1)
            swap(a1,b1);
        if(a2>b2)
            swap(a2,b2);
        if(a1+a2==b1&&b1==b2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    while(clock()*1.0/CLOCKS_PER_SEC<0.999);
}