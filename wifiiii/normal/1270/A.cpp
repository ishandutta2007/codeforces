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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k1,k2;
        cin>>n>>k1>>k2;
        int mx1=0,mx2=0,tmp;
        for(int i=1;i<=k1;++i)
        {
            cin>>tmp;
            mx1=max(mx1,tmp);
        }
        for(int i=1;i<=k2;++i)
        {
            cin>>tmp;
            mx2=max(mx2,tmp);
        }
        if(mx1>mx2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}