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

int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ii cin>>a[i];
        int ok=0;
        for(int i=1;i<n;++i) if(abs(a[i+1]-a[i])>1) ok=i;
        if(ok) cout<<"YES\n"<<ok<<" "<<ok+1<<endl;
        else cout<<"NO\n";
    }
}