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
    ll x, s;
    cin >> x >> s;
    if(x == s && x == 0) return cout << 0 << endl, 0;
    if(x == s) return cout << 1 << endl << s << endl, 0;
    if(x > s || (s-x)&1) return cout << -1 << endl, 0;
    ll a = x, d = (s-x)/2;
    if(a&d)
    {
        cout << 3 << endl;
        cout << (s-x)/2 << " " << (s-x)/2 << " " << x << endl;
    }
    else
    {
        cout << 2 << endl;
        cout << (a^d) << " " << d << endl;
    }
}