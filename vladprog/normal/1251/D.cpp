#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e18;

pii lr[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        for(int i=1;i<=n;i++)
            cin>>lr[i].x>>lr[i].y;
        sort(lr+1,lr+n+1,greater<pii>());
        int lo=0,hi=INF;
        while(lo<hi)
        {
            int mi=(lo+hi+1)/2;
            int sum=0,cnt=0;
            for(int i=1;i<=n;i++)
                if(lr[i].y>=mi&&cnt<(n+1)/2)
                    sum+=max(lr[i].x,mi),
                    cnt++;
                else
                    sum+=lr[i].x;
            if(sum<=s&&cnt>=(n+1)/2)
                lo=mi;
            else
                hi=mi-1;
        }
        cout<<lo<<"\n";
    }
}