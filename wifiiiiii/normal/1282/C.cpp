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

vector<int> va,vb;
const int maxn = 200005;
int c[maxn];
int n,T,a,b;
int check(int T)
{
    int ca = upper_bound(all(va),T) - va.begin();
    int cb = upper_bound(all(vb),T) - vb.begin();
    if(1ll * ca * a + 1ll * cb * b <= 1ll * T)
    {
        int ret = ca + cb;
        T -= a * ca + b * cb;
        int p = min((int)va.size()-ca, T / a);
        T -= p * a;
        ret += p;
        p = min((int)vb.size()-cb, T / b);
        ret += p;
        return ret;
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        va.clear();vb.clear();
        cin>>n>>T>>a>>b;
        for(int i=1;i<=n;++i) cin>>c[i];
        for(int i=1;i<=n;++i)
        {
            int tmp;
            cin>>tmp;
            if(c[i]) vb.push_back(tmp);
            else va.push_back(tmp);
        }
        sort(all(va));
        sort(all(vb));
        int ans = 0;
        for(int i : va) ans = max(ans, check(i - 1));
        for(int i : vb) ans = max(ans, check(i - 1));
        ans = max(ans, check(T));
        cout << ans << endl;
    }
}