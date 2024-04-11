#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int b[N];

void solve()
{
    int n;
    cin>>n;
    n+=2;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(b+1,b+n+1);
    int sum=accumulate(b+1,b+n+1,0ll);
    n-=2;
    if(b[n+1]==sum-b[n+1]-b[n+2])
    {
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
        cout<<"\n";
        return;
    }
    int x=sum-2*b[n+2];
    int pos=find(b+1,b+n+2,x)-b;
    if(pos==n+2)
    {
        cout<<-1<<"\n";
        return;
    }
    for(int i=1;i<=n+1;i++)
        if(i!=pos)
            cout<<b[i]<<" ";
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}