#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

int n, m, r;
pair<int, int> a[1000500];

pair<int, int> ask(int i, int j)
{
    cout<<"? "<<i<<" "<<j<<endl;
    int x;
    cin>>x;
    r=min(r, x);
    return {x, j};
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    r=1e9;
    if (m==1)
    {
        for (int i=1; i<=n; i++)
            ask(1, i);
        cout<<"! "<<r<<endl;
        return 0;
    }

    for (int i=1; i<=m; i++)
        a[i]=ask(1, i);
    sort(a+1, a+m+1);
    int cur = 1;
    for (int j=2; j<=n; j++)
    {
        int i1 = a[cur  ].se;
        int i2 = a[cur+1].se;

        auto p1 = ask(j, i1);
        auto p2 = ask(j, i2);

        while ((p1 > p2) and (cur < m-1))
        {
            cur++;
            p1 = p2;
            p2 = ask(j, a[cur+1].se);
        }
    }

    cout<<"! "<<r<<endl;
    return 0;
}