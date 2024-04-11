#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int a[200005];
int lst[200005],pos[200005];
const int inf = 1e9;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ii cin>>a[i];
        ii pos[i]=-1;
        ii
        {
            lst[i] = pos[a[i]];
            pos[a[i]] = i;
        }
        int ans = inf;
        ii
        {
            if(lst[i] != -1) ans = min(ans, i - lst[i] + 1);
        }
        if(ans == inf) cout << -1 << endl;
        else cout << ans << endl;
    }
}