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
        int n,x,m;
        cin>>n>>x>>m;
        int from=x,to=x;
        while(m--)
        {
            int l,r;
            cin>>l>>r;
            if(max(l,from)<=min(r,to))
                from=min(from,l),
                to=max(to,r);
        }
        cout<<to-from+1<<"\n";
    }
}