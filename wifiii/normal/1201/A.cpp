#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

string a[1005];
int b[1005];
int main()
{
    int n,m;
    cin>>n>>m;
    ii cin>>a[i];
    ij cin>>b[i];
    ll ans = 0;
    for(int i=0;i<m;++i)
    {
        int cnt[6] = {0};
        int m = 0;
        for(int j=1;j<=n;++j)
        {
            cnt[a[j][i]-'A']++;
            m = max(m, cnt[a[j][i]-'A']);
        }
        ans += 1ll * m * b[i+1];
    }
    cout << ans << endl;
}