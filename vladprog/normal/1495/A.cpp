#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ld> x,y;
        for(int _=0;_<2*n;_++)
        {
            int x0,y0;
            cin>>x0>>y0;
            if(x0==0)
                y.push_back(abs(y0));
            else
                x.push_back(abs(x0));
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        ld ans=0;
        for(int i=0;i<n;i++)
            ans+=sqrt(x[i]*x[i]+y[i]*y[i]);
        cout<<ans<<"\n";
    }
}