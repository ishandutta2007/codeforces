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
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        if(a) a--,ans++;
        if(b) b--,ans++;
        if(c) c--,ans++;
        if(a<b) swap(a,b);
        if(a<c) swap(a,c);
        if(a&&b) a--,b--,ans++;
        if(a&&c) a--,c--,ans++;
        if(b&&c) b--,c--,ans++;
        if(a&&b&&c) a--,b--,c--,ans++;
        cout<<ans<<"\n";
    }
}