#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)


int ans[100005];
ll cal(ll n,ll k)
{
    ll l=1,pl=1,ret=0;
    while(n>=pl)
    {
        n-=pl;
        ret+=l*pl;
        l++,pl*=k;
    }
    ret+=n*l;
    return ret;
}
ll a[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,s;
    cin>>n>>s;
    if(s<2*n-1 || s>n*(n+1)/2) {cout<<"No"<<endl;return 0;}
    int k=1;
    while(cal(n,k) > s) k++;
    if(k==1)
    {
        cout<<"Yes"<<endl;
        for(int i=2;i<=n;++i) cout<<i-1<<" ";cout<<endl;
        return 0;
    }
    a[1] = 1; n -= 1; s -= 1;
    ll cur = 0;
    ll i;
    for(i=2;s;++i)
    {
        ll x=1;
        for(;;++x)
        {
            ll tmp = 0, n2 = n, l = i, pl = x;
            while(n2>=pl)
            {
                n2 -= pl;
                tmp += l*pl;
                l++, pl*=k;
            }
            tmp += n2*l;
            if(tmp<=s) break;
        }
        a[i] = x;
        n -= x;
        s -= a[i] * i;
    }
    int ll=1,lr=1,l,r;
    cout<<"Yes"<<endl;
    for(int j=2;j<i;++j)
    {
        l=lr+1,r=lr+a[j];
        int now=ll,cnt=0;
        for(int p=l;p<=r;++p)
        {
            ans[p]=now;
            cout<<ans[p]<<" ";
            if(++cnt == k) cnt=0,now++;
        }
        ll=l,lr=r;
    }
    cout<<endl;
}