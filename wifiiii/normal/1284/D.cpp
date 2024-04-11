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

const int maxn = 250005;

const int M = 1e9+7;
typedef unsigned long long ull;
ull rd1, rd2;
int hsh(int x) {return (x*rd1+rd2)%M;}
int x[maxn],y[maxn],x2[maxn],y2[maxn];
struct node {
    int l,r,id;
    bool operator < (const node & n) const
    {
        return l < n.l || (l==n.l && r<n.r);
    }
}a[maxn],b[maxn];
ll bit[500005][4];
int n;
void add(int x,ll v,int p)
{
    for(;x<=2*n;x+=x&-x) bit[x][p]+=v;
}
ll sum(int x,int p)
{
    ll ret=0;
    for(;x;x-=x&-x) ret+=bit[x][p];
    return ret;
}
vector<int> v1,v2;
int main()
{
    rd1 = mrand() % M;
    rd2 = mrand() % M;
    cin>>n;
    ii cin>>x[i]>>y[i]>>x2[i]>>y2[i],v1.push_back(x[i]),v1.push_back(y[i]),v2.push_back(x2[i]),v2.push_back(y2[i]);
    sort(all(v1));
    sort(all(v2));
    int len=unique(all(v1))-v1.begin();
    ii
    {
        x[i]=lower_bound(v1.begin(),v1.begin()+len,x[i])-v1.begin()+1;
        y[i]=lower_bound(v1.begin(),v1.begin()+len,y[i])-v1.begin()+1;
    }
    len=unique(all(v2))-v2.begin();
    ii
    {
        x2[i]=lower_bound(v2.begin(),v2.begin()+len,x2[i])-v2.begin()+1;
        y2[i]=lower_bound(v2.begin(),v2.begin()+len,y2[i])-v2.begin()+1;
    }
    ull ans1=0,ans2=0;
    ii a[i]={x[i],y[i],hsh(i)},b[i]={x2[i],y2[i],hsh(i)};
    sort(alll(a));
    ii
    {
        int cnt = sum(2*n,2) - sum(a[i].l-1,2);
        ans1 += (sum(2*n,0) - sum(a[i].l-1,0));
        ans1 += 1ull * cnt * a[i].id;
        add(a[i].r, a[i].id, 0);
        add(a[i].r, 1, 2);
    }
    sort(alll(b));
    ii
    {
        int cnt = sum(2*n,3) - sum(b[i].l-1,3);
        ans2 += sum(2*n,1) - sum(b[i].l-1,1);
        ans2 += 1ull * cnt * b[i].id;
        add(b[i].r, b[i].id, 1);
        add(b[i].r, 1, 3);
    }
    if(ans1 == ans2) cout<<"YES";
    else cout<<"NO";
}