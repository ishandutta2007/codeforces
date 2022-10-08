#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,m,x,y,i,j,cnt[N],ans,fix[N];
vector < int > g[N];
void go(int k)
    {
    //cout<<k<<endl;
    fix[k]=1;
    cnt[k]=1;
    for (int i = 0; i < g[k].size(); i++)
        if (fix[g[k][i]]==0)
        {
        go(g[k][i]);
        cnt[k]+=cnt[g[k][i]];
    }
    if (cnt[k]%2==0){
        ans++;
    }
}
int main() {
    cin>>n;
    if (n%2==1){cout<<-1<<endl;return 0;}
    for (i=1;i<=n-1;i++)
        {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    go(1);
    cout<<ans-1<<endl;
    return 0;
}