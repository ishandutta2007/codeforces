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
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005];
vector<int> v[100005];
int f[100005];
int mn[100005],mx[100005];
int b[1000005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        mn[i]=1e9;
        mx[i]=-1e9;
        int ok=1;
        for(int j=0;j<a[i];++j)
        {
            int tmp;
            cin>>tmp;
            v[i].push_back(tmp);
            mn[i]=min(mn[i],tmp);
            mx[i]=max(mx[i],tmp);
            if(j && v[i][j]>v[i][j-1]) ok=0;
        }
        f[i]=ok;
        if(ok) b[mx[i]]++;
    }
    for(int i=1;i<=1000000;++i) b[i]+=b[i-1];
    ll ans = 1ll * n * n;
    for(int i=1;i<=n;++i) if(f[i]) ans -= b[mn[i]];
    cout << ans << endl;
}