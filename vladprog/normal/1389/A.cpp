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
        int l,r;
        cin>>l>>r;
        int x=l,y=2*l;
        if(y<=r)
            cout<<x<<" "<<y<<"\n";
        else
            cout<<-1<<" "<<-1<<"\n";
    }
}