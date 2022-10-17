#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 200005;
int a[maxn],ra[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    ii cin>>a[i],ra[a[i]]=i;
    vector<int> v;
    ll ans1=0;
    for(int i=n;i>=n-k+1;--i) v.push_back(ra[i]),ans1+=i;
    sort(all(v));
    ll ans2=1;
    for(int i=1;i<v.size();++i) ans2=ans2*(v[i]-v[i-1])%998244353;
    cout<<ans1<<" "<<ans2<<endl;
}