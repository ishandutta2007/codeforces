#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int f(int a)
{
    int x=1;
    while(x<a)
        x*=2;
    return x-a;
}

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
        map<int,int> cnt;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            cnt[a]++;
        }
        vector<int> k;
        for(auto[x,y]:cnt)
            k.push_back(y);
        int ans=1e18;
        for(int x=1;x<2*n;x*=2)
            for(int y=1;y<2*n;y*=2)
            {
                int a=0,b=0,c=0;
                int i=0;
                for(;i<k.size()&&a+k[i]<=x;i++) a+=k[i];
                for(;i<k.size()&&b+k[i]<=y;i++) b+=k[i];
                for(;i<k.size()           ;i++) c+=k[i];
                ans=min(ans,f(a)+f(b)+f(c));
            }
        cout<<ans<<"\n";
    }
}