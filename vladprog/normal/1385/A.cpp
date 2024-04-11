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
        int x,y,z;
        cin>>x>>y>>z;
        int a=min(x,y),
            b=min(x,z),
            c=min(y,z);
        if(x==max(a,b)&&
           y==max(a,c)&&
           z==max(b,c))
            cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
        else
            cout<<"NO\n";
    }
}