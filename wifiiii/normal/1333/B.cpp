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

int a[100005],b[100005];
int f[100005][3];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ii cin >> a[i];
        ii cin >> b[i];
        int ok = 1;
        for(int i=1;i<=n;++i)
        {
            f[i][0] = f[i-1][0] | (a[i]==-1);
            f[i][1] = f[i-1][1] | (a[i]==0);
            f[i][2] = f[i-1][2] | (a[i]==1);
        }
        for(int i=n;i>=1;--i)
        {
            if(a[i] < b[i])
            {
                if(!f[i-1][2]) ok = 0;
            }
            else if(a[i] > b[i])
            {
                if(!f[i-1][0]) ok = 0;
            }
            if(!ok) break;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}