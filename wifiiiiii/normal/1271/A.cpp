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
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    b=min(b,c);
    if(e>f)
    {
        int ans = 0;
        int p = min(d, a);
        a -= p, d -= p;
        ans += p * e;
        p = min(d, b);
        ans += p * f;
        cout << ans << endl;
    }
    else
    {
        int ans = 0;
        int p = min(d, b);
        b -= p, d -= p;
        ans += p * f;
        p = min(d, a);
        ans += p * e;
        cout << ans << endl;
    }
}