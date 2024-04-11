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
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int32_t main()
{
    int a,b;cin>>a>>b;
    if(a>b) swap(a,b);
    int Mx = a*b/gcd(a,b);
    int ans = 0;
    int d = b-a;
    vector<int> div;
    for(int i=1;i*i<=d;++i) if(d%i==0) div.push_back(i),div.push_back(d/i);
    for(int i:div)
    {
        int tmp = (i-b%i)%i;
        assert((i-b%i)%i == (i-a%i)%i);
        int cal = (a+tmp) * (b+tmp) / gcd(a+tmp, b+tmp);
        if(cal < Mx) Mx = cal, ans = tmp;
    }
    cout << ans << endl;
}