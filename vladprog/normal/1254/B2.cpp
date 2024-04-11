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

const int N=1e6+100;
const ll INF=1e18;

int n,a[N],b[N];

pii v[N];
int v_size=0;
#define v_push_back(x) v[v_size++]=x
#define v_clear() v_size=0
#define v_size() v_size

ll solve(ll d)
{
    for(int i=1;i<=n;i++)
        b[i]=a[i]%d;
    int pos=0;
    ll ans=0;
    while(true)
    {
        v_clear();
        int cnt=0;
        while(cnt<d)
        {
            while(pos<=n&&!b[pos])
                pos++;
            if(pos>n)
                return ans;
            int cur=min<ll>(d-cnt,b[pos]);
            b[pos]-=cur;
            v_push_back(mp(pos,cur));
            cnt+=cur;
        }
        ll pref=0;
        int mid;
        for(int i=0;i<v_size();i++)
            if((pref+=v[i].y)*2>=d)
            {
                mid=v[i].x;
                break;
            }
        for(int i=0;i<v_size();i++)
            ans+=abs(v[i].x-mid)*ll(v[i].y);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    ll s=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        s+=a[i];
    ll ans=INF;
    for(ll i=2;i*i<=s;i++)
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