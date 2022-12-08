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

const int maxn = 200005;
int a[maxn];
int pre[maxn], b[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k;
        cin>>n>>p>>k;
        ii cin>>a[i];
        sort(alll(a));
        ii pre[i]=pre[i-1]+a[i];
        for(int i=0;i<=k;++i) b[i] = 0;
        int ans = 0;
        ii
        {
            if(i>=k) b[i%k] += a[i];
            if(b[i%k] + pre[i%k] <= p) ans = max(ans, i);
        }
        cout << ans << endl;
    }
}