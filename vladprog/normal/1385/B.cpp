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
        set<int> s;
        for(int _=1;_<=2*n;_++)
        {
            int p;
            cin>>p;
            if(!s.count(p))
                cout<<p<<" ";
            s.insert(p);
        }
        cout<<"\n";
    }
}