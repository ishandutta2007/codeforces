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

    int x;
    cin>>x;
    while(x>=10)
    {
        int ans=0;
        while(x)
            ans+=x%10,
            x/=10;
        x=ans;
    }
    cout<<x;
}