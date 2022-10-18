#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    set<int> s;
    for(int i=0;i<=3*n;i++)
        s.insert(i);
    for(int i=1;i<=n;i++)
        s.erase(a[i]);
    for(int i=1;i<=n;i++)
    {
        b[i]=*s.begin();
        s.erase(s.begin());
        if(a[i]!=a[i+1])
            s.insert(a[i]);
    }
    s.clear();
    for(int i=0;i<=3*n;i++)
        s.insert(i);
    bool ok=true;
    for(int i=1;i<=n;i++)
    {
        s.erase(b[i]);
        if(*s.begin()!=a[i])
            ok=false;
    }
    if(ok)
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
    else
        cout<<-1;
}