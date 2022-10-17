#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

#define int ll
int32_t main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        int ok=1;
        int L = m, R = m + 1;
        int cur = 0;
        for(int i=1;i<=n;++i)
        {
            int t,l,r;
            cin>>t>>l>>r;
            ++r;
            int dt = t - cur;
            int nL = L - dt, nR = R + dt;
            if(min(nR, r) - max(l, nL) <= 0) ok = 0;
            else
            {
                L = max(nL, l);
                R = min(nR, r);
            }
            cur = t;
//            cout << i << " " << L << " " << R << endl;
        }
        cout << (ok?"YES":"NO") << endl;
    }
}