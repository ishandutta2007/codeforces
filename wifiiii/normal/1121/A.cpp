#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
#define pb push_back
int a[105],b[105],tag[105],cnt[105];
priority_queue<pair<int,int> > q[105];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        int t;cin>>t;
        b[i] = t;
        q[t].push({a[i],i});
    }
    int ans = 0;    
    for(int i=1;i<=k;++i)
    {
        int t;cin>>t;
        if(q[b[t]].top().second!=t) ans++;
    }
    cout << ans << endl;
}