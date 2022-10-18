#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,B=25;

int cnt[B][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int b=0;b<B;b++)
        for(int i=1;i<N;i++)
            cnt[b][i]=cnt[b][i-1]+!((i>>b)&1);

    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int ans=1e9;
        for(int b=0;b<25;b++)
        {
            int res=cnt[b][r]-cnt[b][l-1];
            ans=min(ans,res);
        }
        cout<<ans<<"\n";
    }
}