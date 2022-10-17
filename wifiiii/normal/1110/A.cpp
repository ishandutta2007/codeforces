#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005];
int main()
{
    int b,k;
    cin>>b>>k;
    for(int i=1;i<=k;++i) cin>>a[i];
    if(b%2==0)
    {
        if(!(a[k]&1)) cout<<"even"<<endl;
        else cout<<"odd"<<endl;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=k;++i) if(a[i]&1) ans++;
    if(ans&1) cout<<"odd"<<endl;
    else cout<<"even"<<endl;
}