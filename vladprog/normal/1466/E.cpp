#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100,K=60,MOD=1e9+7;

int x[N];
int bit[K];
int res[N];

inline void upd(int&var,int val)
{
    var=(var+val)%MOD;
}

inline int shift(int x,int y)
{
    return (1ll<<y)%MOD*x;
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
        for(int i=1;i<=n;i++)
            cin>>x[i];
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;i++)
            for(int j=0;j<K;j++)
                if((x[i]>>j)&1)
                    upd(bit[j],1);
        for(int i=1;i<=n;i++)
            res[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<K;j++)
                if((x[i]>>j)&1)
                    upd(res[i],shift(n,j));
                else
                    upd(res[i],shift(bit[j],j));
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;i++)
            for(int j=0;j<K;j++)
                if((x[i]>>j)&1)
                    upd(bit[j],res[i]);
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<K;j++)
                if((x[i]>>j)&1)
                    upd(ans,shift(bit[j],j));
        cout<<ans<<"\n";
    }
}