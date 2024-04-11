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

int a[105],vis[105];
vector<int> v[105];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=2*n;++i) cin>>a[i];
    int ans = 0;
    for(int i=1;i<=2*n;++i)
    {
        if(vis[a[i]]) continue;
        vis[a[i]] = 1;
        for(int j=i+1;a[j]!=a[i];++j) if(!vis[a[j]]) ++ans;
    }
    cout << ans << endl;
}