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

const int N=1e6+100,INF=1e18;

int n,a[N],b[N];

int solve(int d)
{
    for(int i=1;i<=n;i++)
        b[i]=a[i]%d;
    int pos=0,ans=0;
    while(true)
    {
        vector<pii> v;
        int cnt=0;
        while(cnt<d)
        {
            while(pos<=n&&!b[pos])
                pos++;
            if(pos>n)
                return ans;
            int cur=min(d-cnt,b[pos]);
            b[pos]-=cur;
            v.push_back(mp(pos,cur));
            cnt+=cur;
        }
        sort(v.begin(),v.end());
        int pref=0,mid;
        for(auto p:v)
            if((pref+=p.y)*2>=d)
            {
                mid=p.x;
                break;
            }
        for(auto p:v)
            ans+=abs(p.x-mid)*p.y;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        s+=a[i];
    int ans=INF;
    for(int i=2;i*i<=s;i++)
        if(s%i==0)
        {
            ans=min(ans,solve(i));
            while(s%i==0)
                s/=i;
        }
    if(s>1)
        ans=min(ans,solve(s));
    cout<<(ans==INF?-1:ans);
}