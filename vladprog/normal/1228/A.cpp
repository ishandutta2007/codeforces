#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l,r;
    cin>>l>>r;
    for(int x=l;x<=r;x++)
    {
        set<int>s;
        int t=x;
        bool ok=true;
        while(t)
        {
            int c=t%10;
            if(s.count(c))
                ok=false;
            s.insert(c);
            t/=10;
        }
        if(ok)
            cout<<x,exit(0);
    }
    cout<<-1;
}