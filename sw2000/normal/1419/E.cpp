#include <cmath> //
#include <cstdio> //
#include <cstdlib> //
#include <cstring> //
#include <algorithm> //STL 
#include <cmath>
#include <list> //STL 
#include <map> //STL 
#include <iostream>
#include <queue> //STL 
#include <set> //STL #
#include <stack> //STL 
#include <string> //
#include <vector> //STL 
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
const int N=1e5+10;
const ll mod=998244353;
const double PI=acos(0)*2;

vi v,ans;//
void dfs(int id)
{
    vi tmp=ans;//tmpans1
    if(tmp.empty())tmp.push_back(1);
    else tmp.insert(tmp.end()-1,1);
    reverse(tmp.begin(),tmp.end());

    while(1)//24816
    {
        for(int i=0;i<tmp.size();i++)
        {
            ans.push_back(tmp[i]*v[id]);
        }
        id++;
        if(id==v.size())return;
        if(v[id-1]%v[id]==0)
        {
            v[id]*=v[id-1];
            if(id>1&&v[id]%v[id-2])
                reverse(tmp.begin(),tmp.end());
            //
        }

        else break;
    }
    dfs(id);//
}
void solve()
{
    v.clear();ans.clear();
    int n;cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            v.push_back(i);
        }
    }
    if(n!=1)v.push_back(n);

    if(v.size()==2&&v[0]!=v[1])
    {
        cout<<v[0]<<' '<<v[1]<<' '<<v[0]*v[1]<<endl;
        cout<<1<<endl;
    }
    else
    {
        dfs(0);
        for(auto i:ans)cout<<i<<' ';cout<<endl;
        cout<<0<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int n;cin>>n;
    while(n--)
    {
        solve();
    }
    return 0;
}