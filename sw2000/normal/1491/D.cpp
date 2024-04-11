#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
ll u,v;
bool solve()
{
    cin>>u>>v;
    vi uu,vv;
    for(int i=0;i<30;i++)
    {
        if(u&1<<i)uu.push_back(i);
        if(v&1<<i)vv.push_back(i);
    }
    if(uu.size()<vv.size())return 0;
    reverse(uu.begin(),uu.end());
    reverse(vv.begin(),vv.end());
//    for(auto i:vv)cout<<i<<' ';cout<<endl;

    int f=0;
    for(int i=0;i<uu.size();i++)
    {
        if(i==(int)vv.size())return 0;
        if(uu[i]<vv[i])
        {
            f=i;
            break;
        }
        if(uu[i]>vv[i])return 0;
    }
    while(uu.size()!=vv.size())uu.erase(uu.begin()+f+1);
    for(int i=0;i<uu.size();i++)if(uu[i]>vv[i])return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)cout<<(solve()?"YES":"NO")<<endl;
    return 0;
}