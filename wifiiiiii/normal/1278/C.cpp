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

int a[200005];
int c[200005];
const int K = 100002;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=2*n;++i) cin>>a[i];
        for(int i=-n;i<=n;++i) c[i+K]=-1;
        int c1=0,c2=0;
        for(int i=1;i<=2*n;++i) if(a[i]==1) c1++;else c2++;
        if(c1==c2) {cout<<0<<endl;continue;}
        c1=0,c2=0;
        c[K] = n;
        for(int i=2*n;i>=n+1;--i)
        {
            if(a[i] == 1) c1++;
            else c2++;
            c[c1-c2+K]=i-n-1;
        }
        c1=0,c2=0;
        int ans = 2*n;
        ans = min(ans, c[K]+n);
        for(int i=1;i<=n;++i)
        {
            if(a[i] == 1) c1++;
            else c2++;
            if(c[c2-c1+K]!=-1) ans = min(ans, c[c2-c1+K]+n-i);
        }
        cout << ans << endl;
    }
}