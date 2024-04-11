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

int a[400005],b[400005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ii cin >> a[i];
    ll ans = 0;
    for(int k=0;k<=25;++k)
    {
        ii b[i]=a[i]%(1<<(k+1));
        sort(alll(b));
        int tmp = 0;
        ii
        {
            tmp += lower_bound(b+1+i,b+1+n,(1<<(k+1))-b[i]) - lower_bound(b+1+i,b+1+n,(1<<k)-b[i]);
            tmp += lower_bound(b+1+i,b+1+n,(1<<(k+2))-1-b[i]) - lower_bound(b+1+i,b+1+n,(1<<k)+(1<<(k+1))-b[i]);
        }
        if(tmp & 1) ans |= 1 << k;
    }
    cout << ans << endl;
}