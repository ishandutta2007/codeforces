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
const int N=1e6+100;
const ll mod=1e9+7;
const double PI=acos(0)*2;
vi v[40];
int cnt=0;
vector<pii>ans;
void f(vi &a)
{
    int n=a.size();
    int base=1;
    while(base!=n)
    {
        for(int i=0;i<n;i+=base*2)
        {
            for(int j=0;j<base;j++)
            {
                ans.push_back({a[i+j],a[i+base+j]});
            }
        }
        base*=2;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int n;cin>>n;
    int tot=0;
    for(int i=30;~i;i--)if(n&(1<<i))
    {
        for(int j=0;j<(1<<i);j++)
        {
            v[cnt].push_back(++tot);
        }
        f(v[cnt]);
        cnt++;
    }
    for(int i=cnt-1;i>1;)
    {
        int m=v[i].size();
        if(v[i].size()==v[i-1].size())
        {
            for(int j=0;j<m;j++)
                ans.push_back({v[i][j],v[i-1][j]});
            for(int j=0;j<m;j++)
                v[i-1].push_back(v[i][j]);
            i--;
        }
        else
        {
            for(int j=0;j<m;j++)
            {
                int a=*(v[0].end()-1);
                v[0].erase(v[0].end()-1);
                ans.push_back({a,v[i][j]});
                v[i].push_back(a);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i.x<<' '<<i.y<<endl;
    return 0;
}