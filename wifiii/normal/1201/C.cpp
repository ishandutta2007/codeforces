#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll a[200005];
ll sum[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ii cin>>a[i];
    sort(a+1,a+1+n);
    ll mid = n/2+1;
    ii sum[i]=sum[i-1]+a[i];
    for(ll i = mid+1; i <= n+1; ++i)
    {
        if(i>n || (i-mid+1)*a[i] - (sum[i] - sum[mid-1]) > k)
        {
            ll p = i - 1;
            k -= (p-mid+1) * a[p] - (sum[p] - sum[mid-1]);
            cout << a[p] + k / (p-mid+1) << endl;
            return 0;
        }
    }
}