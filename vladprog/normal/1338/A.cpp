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
        int n;
        cin>>n;
        int m=-1e18,d=0;
        while(n--)
        {
            int a;
            cin>>a;
            m=max(m,a);
            d=max(d,m-a);
        }
        int k=0;
        while(d)
            k++,
            d>>=1;
        cout<<k<<"\n";
    }
}