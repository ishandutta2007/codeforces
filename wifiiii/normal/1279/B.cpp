#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll a[100005],p[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll s;
        cin>>n>>s;
        ii cin>>a[i];
        ii p[i]=p[i-1]+a[i];
        int ans = 0, mx = 0;
        if(p[n] <= s);
        else
        for(int i=1;i<=n;++i)
        {
            if(p[i-1] > s) break;
            int pos = upper_bound(alll(p),s+a[i])-p;
            if(pos > mx)
            {
                ans = i;
                mx = pos;
            }
        }
        cout << ans << endl;
    }
    
}