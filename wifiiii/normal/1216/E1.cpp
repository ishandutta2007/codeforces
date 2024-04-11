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


const int maxn = 1000007;
int a[maxn];bool mp[maxn];
struct node
{
    ll a,id,pos1,pos2;
    char ans;
    bool operator < (const node & n) const
    {
        return a<n.a;
    }
}b[505];
int main()
{
    int p = 1;
    for(int i=1;i<=6;++i) p*=10,mp[p]=1;
    int p2 = 1;
    for(int i=1;i<maxn;++i)
    {
        if(mp[i]) p2++;
        a[i]=a[i-1]+p2;
    }
    string str;
    for(int i=0;i<maxn;++i)
    {
        str += to_string(i);
        if(str.size() > maxn) break;
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;++i) cin>>b[i].a,b[i].id=i;
    sort(b+1,b+1+q);
    int now = 1;
    ll sum = 0;
    for(int i=1;i<maxn;++i)
    {
        sum += a[i];
        while(now <= q && sum >= b[now].a) b[now].ans = str[b[now].a - sum + a[i]], now++;
        if(now > q) break;
    }
    sort(b+1,b+1+q,[&](node a,node b){return a.id<b.id;});
    for(int i=1;i<=q;++i) cout<<b[i].ans<<endl;
}