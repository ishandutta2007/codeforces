#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second
 
int n, m;
vector <pii> vs, vus;
 
signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    int t, l, r;
    for (int i=1; i<=m; i++)
    {
        cin>>t>>l>>r;
        if (t==0) vus.push_back({l, r});
        else vs.push_back({l, r});
    }
 
    sort(vs.begin(), vs.end());
    vector <int> ans;
    ans.assign(n+1, 1);
 
    int MAXA=1000005;
    for (pii p: vs) 
    {
        if (ans[p.XX]==1) 
        {
            ans[p.XX]=MAXA;
            MAXA-=1000;
        }
        for (int i=p.XX; i<=p.YY; i++) ans[i]=ans[p.XX];
    }
    ans[0]=999999999;
    for (int i=1; i<=n; i++) if (ans[i]==1) ans[i]=ans[i-1]-1;
    for (pii p: vus) if (ans[p.XX]<=ans[p.YY]) 
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
 
 
}