
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
    int x,y,z,id,f;
    bool operator < (const node  & n) const
    {
        return x<n.x || (x==n.x && y<n.y) || (x==n.x && y==n.y && z<n.z);
    }
}a[50005],b[50005];
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i].x>>a[i].y>>a[i].z,a[i].id=i,a[i].f=0;
    sort(a+1,a+1+n);
    vector<pair<int,int>> ans;
    for(int i=1;i+1<=n;)
    {
        if(a[i].x == a[i+1].x && a[i].y == a[i+1].y) ans.push_back({a[i].id,a[i+1].id}), a[i].f=a[i+1].f=1,i+=2;
        else ++i;
    }
    int tp=0;
    for(int i=1;i<=n;++i) if(!a[i].f) b[++tp]=a[i];
    n = tp;
    for(int i=1;i<=n;++i) a[i]=b[i];
    for(int i=1;i+1<=n;)
    {
        if(a[i].x == a[i+1].x) ans.push_back({a[i].id,a[i+1].id}), a[i].f=a[i+1].f=1,i+=2;
        else ++i;
    }
    tp = 0;
    for(int i=1;i<=n;++i) if(!a[i].f) b[++tp]=a[i];
    n = tp;
    for(int i=1;i<=n;++i) a[i]=b[i];
    for(int i=1;i<=n;i+=2) ans.push_back({a[i].id,a[i+1].id});
    for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
}