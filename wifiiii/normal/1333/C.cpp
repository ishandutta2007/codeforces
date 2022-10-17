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

map<ll, int> mp;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll sum = 0, ans = 0;
    int last = 0;
    mp[0] = 0;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin >> x;
        sum += x;
        if(mp.count(sum)) last = max(last, mp[sum] + 1);
        ans += i - last;
        mp[sum] = i;
    }
    cout << ans << endl;
}