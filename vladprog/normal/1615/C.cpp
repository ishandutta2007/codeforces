#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int INF=1e9;

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
        string a,b;
        cin>>a>>b;
        int cnt[2][2]={};
        for(int i=0;i<n;i++)
            cnt[a[i]-'0'][b[i]-'0']++;
        int even=(cnt[1][0]==cnt[0][1]?cnt[1][0]:INF)*2;
        int odd=(cnt[0][0]+1==cnt[1][1]?cnt[0][0]:INF)*2+1;
        int ans=min(even,odd);
        cout<<(ans>=INF?-1:ans)<<"\n";
    }
}