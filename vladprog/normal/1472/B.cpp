#include <bits/stdc++.h>

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
        int n;
        cin>>n;
        int cnt[3]={};
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            cnt[x]++;
        }
        int sum=cnt[1]+2*cnt[2];
        cout<<(sum%4==0||
               sum%2==0&&cnt[1]?
               "YES\n":"NO\n");
    }
}