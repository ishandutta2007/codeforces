#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 mrand(random_device());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1005];
int main()
{
    int n,m;
    cin>>n>>m;
    if(n>m) return cout<<0<<endl,0;
    ii cin>>a[i];
    sort(alll(a));
    ll ans = 1;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            ans = ans * (a[j] - a[i]) % m;
    cout << ans << endl;
}