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

int a[200005];
int ans[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a[n+1]=0;
        ii cin>>a[i];
        int ok=1;
        ii if(a[i]!=a[1]) {ok=0;break;}
        if(ok)
        {
            cout<<1<<endl;
            ii cout<<1<<" ";cout<<endl;
            continue;
        }
        if(n%2==0)
        {
            cout<<2<<endl;
            ii cout<<(i&1)+1<<" ";cout<<endl;
            continue;
        }
        int k=0;
        if(a[1] == a[n])
        {
            cout<<2<<endl;
            ii cout<<(i&1)+1<<" ";cout<<endl;
            continue;;
        }
        ii if(a[i]==a[i+1]) {k=i;break;}
        if(!k)
        {
            cout<<3<<endl;
            for(int i=1;i<n;++i) cout<<(i&1)+1<<" ";cout<<3<<endl;
            continue;
        }
        ans[k]=ans[k+1]=1;
        for(int i=k-1;i>=1;--i) ans[i]=3-ans[i+1];
        for(int i=k+2;i<=n;++i) ans[i]=3-ans[i-1];
        cout<<2<<endl;
        ii cout<<ans[i]<<" ";cout<<endl;
    }
}