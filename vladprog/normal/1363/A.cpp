#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int cnt[2]={};
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            cnt[a%2]++;
        }
        if(cnt[1]&&
           (x<n&&(x%2||cnt[0])||
            x==n&&cnt[1]%2))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}