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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a=0,b=0;
        int n;
        cin>>n;
        int ok=1;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            if(x<a || y<b) ok = 0;
            if(y-b > x-a) ok = 0;
            a=x,b=y;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}