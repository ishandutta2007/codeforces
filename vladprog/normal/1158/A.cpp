#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e5+100;

int b[N],g[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++)
        cin>>g[i];
    sort(b+1,b+n+1,greater<int>());
    sort(g+1,g+m+1);
    if(b[1]>g[1])
        cout<<-1,exit(0);
    if(b[1]==g[1])
        cout<<accumulate(b+2,b+n+1,0ll)*m+
              accumulate(g+1,g+m+1,0ll);
    else
        cout<<accumulate(b+2,b+n+1,0ll)*m+
              accumulate(g+1,g+m+1,0ll)+
              b[1]-b[2];
}