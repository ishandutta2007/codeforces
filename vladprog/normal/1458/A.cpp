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

    int n,m;
    cin>>n>>m;
    int p;
    cin>>p;
    int g=0;
    for(int i=1;i<=n-1;i++)
    {
        int a;
        cin>>a;
        g=__gcd(g,a-p);
        p=a;
    }
    for(int i=1;i<=m;i++)
    {
        int b;
        cin>>b;
        cout<<abs(__gcd(g,p+b))<<" ";
    }
}