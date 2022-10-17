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
    int n,m,k;
    cin>>n>>m>>k;
    string ans = string(m-1,'L') + string(n-1,'U');
    for(int i=1;i<=n;++i) {
        if(i&1) ans += string(m-1,'R');
        else ans += string(m-1,'L');
        ans += 'D';
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}