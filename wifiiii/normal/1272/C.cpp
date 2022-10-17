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

int ok[300];
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=1;i<=k;++i)
    {
        char c;
        cin>>c;
        ok[c]++;
    }
    int cnt = 0;
    vector<int> v;
    for(int i=0;i<=s.size();++i)
    {
        if(ok[s[i]]) cnt++;
        else
        {
            if(cnt) v.push_back(cnt);
            cnt = 0;
        }
    }
    ll ans = 0;
    for(int i : v) ans += 1ll * i * (i+1) / 2;
    cout << ans << endl;
}