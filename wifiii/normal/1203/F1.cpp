#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

struct node
{
    int a,b;
    bool operator < (const node &n) const
    {
        if((b<0 && n.b>=0) || (b>=0 && n.b<0)) return b>=0;
        if(b>=0) return a<n.a;
        if(b<0) return a+b<n.a+n.b;
        return 1;
    }
}a[104];
int main()
{
    int n,r;
    cin>>n>>r;
    ii cin>>a[i].a>>a[i].b;
    sort(a+1,a+1+n);
    int i=1;
    for(;i<=n;++i)
    {
        if(a[i].b<0) break;
        if(r < a[i].a) return cout<<"NO"<<endl,0;
        r += a[i].b;
    }
    int lst=r;
    for(int j=i;j<=n;++j) lst+=a[j].b;
    if(lst<0) return cout<<"NO"<<endl,0;
    for(;i<=n;++i)
    {
        if(lst<a[i].a+a[i].b) return cout<<"NO"<<endl,0;
        lst-=a[i].b;
    }
    cout<<"YES"<<endl;
}