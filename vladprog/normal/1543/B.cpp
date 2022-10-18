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
        int s=0;
        for(int _=0;_<n;_++)
        {
            int a;
            cin>>a;
            s+=a;
        }
        int k=s%n;
        cout<<k*(n-k)<<"\n";
    }
}