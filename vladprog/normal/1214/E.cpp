#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

#define mp make_pair

const int N=1e5+100;

pii dv[N];
vector<pii> g[2*N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>dv[i].x,dv[i].y=i;
    sort(dv+1,dv+n+1,greater<pii>());
    for(int i=1;i<=n;i++)
        g[i].push_back(mp(0,2*dv[i].y-1)),
        g[i+dv[i].x].push_back(mp(1,2*dv[i].y));
    for(int i=1;i<=2*n;i++)
        sort(g[i].begin(),g[i].end());
    for(int i=2;i<=2*n;i++)
        for(pii v:g[i])
            cout<<g[i-1][0].y<<" "<<v.y<<"\n";
}