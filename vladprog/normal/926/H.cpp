#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long

const ll mod=1e9+7, mod1=1e9+17, bas=29;
const ll nmax=1e5+10;
ll st[nmax][2], h[nmax][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin>>n>>k;
    pair<ll, ll> a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i].ff, a[i].ss=i;
    string s;
    cin>>s;
    sort(a, a+n);
    reverse(a, a+n);
    ll r=0, w=0, o=0, q=0, t=0;
    for(int i=0; i<n; i++)
    {
        int t=-1;
        if(s[a[i].ss]!='R')
        {
            if(s[a[i].ss]=='W')
                w+=a[i].ff, t=1;
            if(s[a[i].ss]=='O')
                o+=a[i].ff, t=0;
            q++;
        }
        if(q==k)
        {
            if(o && w)
                break;
            q--;
            if(t==1)
                w-=a[i].ff;
            else
                o-=a[i].ff;
        }
    }
    if(q==k && w && o)
        q=1, w+=o;
    else
        t++;

    o=0, q=0;
    for(int i=0; i<n; i++)
    {
        int t=-1;
        if(s[a[i].ss]!='W')
        {
            if(s[a[i].ss]=='R')
                r+=a[i].ff, t=1;
            if(s[a[i].ss]=='O')
                o+=a[i].ff, t=0;
            q++;
        }
        if(q==k)
        {
            if(o && r)
                break;
            q--;
            if(t==1)
                r-=a[i].ff;
            else
                o-=a[i].ff;
        }
    }
    if(q==k && r && o)
        q=1, r+=o;
    else
        t++;
    if(t==2)
        cout<<-1;
    else
        cout<<max(r, w);
}