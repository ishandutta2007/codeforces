#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int x;cin>>x;int a[3];for(int i=0;i<3;++i) cin>>a[i];
        bool used[3]={0};int cur=x;
        while(cur!=0)
        {
            used[cur-1]=true;
            cur=a[cur-1];
        }
        puts((used[0] && used[1] && used[2]) ? "YES" : "NO");
    }
    return 0;
}