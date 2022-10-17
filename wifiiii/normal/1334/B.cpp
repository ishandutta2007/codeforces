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

int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>>n>>w;
        ii cin>>a[i];
        sort(alll(a));
        reverse(alll(a));
        int ans=0;
        ll s=0;
        for(int i=1;i<=n;++i) {
            s += a[i];
            if(s >= 1ll * w * i) ans = i;
            else break;
        }
        cout << ans << endl;
    }
}