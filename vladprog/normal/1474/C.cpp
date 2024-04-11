#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int n;
int a[2*N];

bool solve(int x)
{
    multiset<int,greater<int>> s(a+1,a+2*n+1);
    int x0=x;
    vector<pii> ans;
    while(!s.empty())
    {
        int p=*s.begin();
        s.erase(s.begin());
        int q=x-p;
        if(!s.count(q))
            return false;
        s.erase(s.find(q));
        ans.push_back({p,q});
        x=p;
    }
    cout<<"YES\n";
    cout<<x0<<"\n";
    for(auto p:ans)
        cout<<p.x<<" "<<p.y<<"\n";
    return true;
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
        multiset<int> s;
        cin>>n;
        for(int i=1;i<=2*n;i++)
            cin>>a[i];
        int mx=*max_element(a+1,a+2*n+1);
        bool ok=false;
        for(int i=1;i<=2*n;i++)
            if(solve(mx+a[i]))
            {
                ok=true;
                break;
            }
        if(!ok)
            cout<<"NO\n";
    }
}