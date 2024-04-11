#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int solve(int n)
{
    for(int d=2;d*d<=n;d++)
        if(n%d==0)
            return n/d;
    return n/n;
}

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
        int x=solve(n);
        cout<<x<<" "<<n-x<<"\n";
    }
}