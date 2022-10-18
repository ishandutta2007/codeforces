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
        int n,k;
        cin>>n>>k;
        map<int,int> cnt;
        while(n--)
        {
            int a;
            cin>>a;
            for(int i=0;a;i++)
                cnt[i]+=a%k,
                a/=k;
        }
        bool ok=true;
        for(auto p:cnt)
            if(p.second>1)
                ok=false;
        cout<<(ok?"YES\n":"NO\n");
    }
}