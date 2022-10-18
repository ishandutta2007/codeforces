#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second

const int N=2e5+100;

int a[N];
array<int,3> lrd[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m,n,k,t;
    cin>>m>>n>>k>>t;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    sort(a+1,a+m+1,greater<>());
    for(int i=1;i<=k;i++)
        cin>>lrd[i][0]>>lrd[i][1]>>lrd[i][2];
    sort(lrd+1,lrd+k+1);
    int lo=0,hi=m;
    while(lo<hi)
    {
        int mi=(lo+hi+1)/2;
        vector<pii> segs;
        int mn=a[mi];
        for(int i=1;i<=k;i++)
            if(lrd[i][2]>mn)
                if(segs.empty()||segs.back().y<lrd[i][0])
                    segs.push_back(mp(lrd[i][0],lrd[i][1]));
                else
                    segs.back().y=max(segs.back().y,lrd[i][1]);
        int need=n+1;
        for(auto p:segs)
            need+=2*(p.y-p.x+1);
        if(need<=t)
            lo=mi;
        else
            hi=mi-1;
    }
    cout<<lo;
}