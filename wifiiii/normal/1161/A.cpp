#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

int ok[100005][3],cnt[100005];
int main()
{
    memset(ok,-1,sizeof(ok));
    int n,k;
    cin>>n>>k;
    ok[1][0] = 0, ok[n][2] = 0;
    for(int i=1;i<=k;++i)
    {
        int t;cin>>t;
        cnt[t]++;
        if(cnt[t-1]) ok[t-1][2] = 0;
        if(cnt[t]) ok[t][1] = 0;
        if(cnt[t+1]) ok[t+1][0] = 0;
    }
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        if(ok[i][0]) ans++;
        if(ok[i][1]) ans++;
        if(ok[i][2]) ans++;
    }
    cout << ans << endl;
}