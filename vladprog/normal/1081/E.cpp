#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e6 + 11;

int a[N];
vector<pair<ll,ll> > v[N];
vector<bool> dp[N];
vector<int> pr[N];

inline bool good(ll x, ll y)
{
    if (x>=y) return false;
    ll p=y-x;
    ll c=x+p;
    ll d=sqrt(c);
    if (d*d==c) return true;
    return false;
}

inline int get(ll x, ll y)
{
    return y-x;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n/2; i++)
    {
        cin>>a[i];
        for (int p=1; p<=(int)sqrt(a[i]); p++)
            if (a[i]%p==0)
        {
            int t1=p;
            int t2=a[i]/p;
            if ((t2+t1)%2==0&&(t2-t1)%2==0&&t2-t1>0)
                v[i].pb(mp((t2-t1)/2,(t2+t1)/2));
        }
        //cout<<a[i]<<" - "<<endl;
        for (int j=0; j<v[i].size(); j++)
        {
            v[i][j].ff=v[i][j].ff*v[i][j].ff;
            v[i][j].ss=v[i][j].ss*v[i][j].ss;
            //cout<<v[i][j].ff<<" "<<v[i][j].ss<<endl;
            //cout<<endl;
        }
    }
    for (int j=0; j<v[1].size(); j++)
    {
        dp[1].pb(1);
        pr[1].pb(0);
    }
    for (int i=2; i<=n/2; i++)
    {
        for (int j=0; j<v[i].size(); j++)
        {
            int x=0,prr=0;
            for (int t=0; t<v[i-1].size(); t++)
                if (dp[i-1][t]==1&&good(v[i-1][t].ss,v[i][j].ff))
            {
                x=1;
                prr=t;
                break;
            }
            dp[i].pb(x);
            pr[i].pb(prr);
        }
    }
    int xx=-1;
    for (int j=0; j<v[n/2].size(); j++)
    if (dp[n/2][j]==1) {xx=j; break;}
    if (xx==-1) {cout<<"No"<<endl; return 0;}
    cout<<"Yes"<<endl;
    vector<ll> ans;
    for (int i=n/2; i>=1; i--)
    {
        ans.pb(a[i]);
        if (i==1)
        {
            ans.pb(v[i][xx].ff);
            break;
        }
        ll c2=v[i][xx].ff;
        int prr=pr[i][xx];
        ll c1=v[i-1][prr].ss;
        //cout<<c1<<" "<<c2<<" - "<<get(c1,c2)<<endl;
        ans.pb(get(c1,c2));
        xx=prr;
    }
    for (int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<" ";
    cout<<endl;
}