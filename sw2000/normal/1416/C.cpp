#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=3e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
int n,arr[40][N],brr[40][N];

int x;
ll c0[40],c1[40],ans;
void dfs(vi &v,int d)
{
    if(v.size()<=1)return;
    vi v0,v1;
    for(auto i:v)
    {
        if(i&(1<<d))
        {
            v1.push_back(i);
            c1[d]+=v0.size();
        }
        else
        {
            v0.push_back(i);
            c0[d]+=v1.size();
        }
    }
    if(d)
    {
        dfs(v0,d-1);
        dfs(v1,d-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n;
    vi v;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
//        for(int j=0;j<30;j++)
//        {
//            arr[j][i]=(a&(1<<j))!=0;
//        }
    }
    dfs(v,30);
    for(int i=0;i<=30;i++)
    {
        if(c1[i]<c0[i])
        {
            ans+=c1[i];
            x|=(1<<i);
        }
        else ans+=c0[i];
    }
    cout<<ans<<' '<<x;
//    for(int i=0;i<=3;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            cout<<arr[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    return 0;
}