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
 
struct node
{
    int a,id;
    bool operator < (const node & n) const
    {
        return a>n.a;
    }
}a[1005];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i].a,a[i].id=i;
    sort(a+1,a+1+n);
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        ans += 1ll * (i-1) * a[i].a;
    }
    cout << ans + n << endl;
    for(int i=1;i<=n;++i) cout<<a[i].id<<" ";cout<<endl;
}