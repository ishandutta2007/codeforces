#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e5+100;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;
    deque<int> d;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        d.push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=d.front();
        d.pop_front();
        b[i]=d.front();
        d.pop_front();
        d.push_front(max(a[i],b[i]));
        d.push_back(min(a[i],b[i]));
    }
    while(q--)
    {
        int m;
        cin>>m;
        if(m<=n)
            cout<<a[m]<<" "<<b[m]<<"\n";
        else
            cout<<d[0]<<" "<<d[(m-n-1)%(n-1)+1]<<"\n";
    }
}