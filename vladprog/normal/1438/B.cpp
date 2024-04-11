#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool solve()
{
    int n;
    cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    return s.size()<n;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0)^(int)(new char));

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");
}