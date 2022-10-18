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
        int n,x;
        cin>>n>>x;
        set<int> s;
        while(n--)
        {
            int a;
            cin>>a;
            s.insert(a);
        }
        int v=0;
        while(true)
            if(s.count(v+1))
                v++;
            else if(x)
                v++,x--;
            else
                break;
        cout<<v<<"\n";
    }
}