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
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> vis(n+1);
        int cnt = 0, nm = -1;
        for(int i=1;i<=n;++i)
        {
            int k;
            cin >> k;
            int f = 0;
            for(int j=1;j<=k;++j) {
                int tmp;
                cin >> tmp;
                if(!f && !vis[tmp]) f = 1, vis[tmp] = 1, ++cnt;
            }
            if(!f) nm = i;
        }
        if(cnt == n) cout << "OPTIMAL" << endl;
        else
        {
            int x = 0;
            for(int i=1;i<=n;++i) if(!vis[i]) {x=i;break;}
            cout << "IMPROVE" << endl;
            cout << nm << " " << x << endl;
        }
    }
}