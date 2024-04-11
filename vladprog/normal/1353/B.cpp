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
        int n,k;
        cin>>n>>k;
        multiset<int> a;
        multiset<int,greater<int>> b;
        for(int _=0;_<n;_++)
        {
            int x;
            cin>>x;
            a.insert(x);
        }
        for(int _=0;_<n;_++)
        {
            int y;
            cin>>y;
            b.insert(y);
        }
        while(k--)
        {
            int x=*a.begin();
            int y=*b.begin();
            if(x<y)
            {
                a.erase(a.begin());
                b.erase(b.begin());
                a.insert(y);
                b.insert(x);
            }
        }
        cout<<accumulate(a.begin(),a.end(),0ll)<<"\n";
    }
}