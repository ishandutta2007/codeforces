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
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
bool vis[N];
vi prm;
int n,m,arr[N];
void solve()
{
unordered_map<int,int>mp,mmp;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b=1;cin>>a;
        for(int j=0;;j++)
        {
            if(prm[j]*prm[j]>a)break;

            int cnt=0;
            while(a%prm[j]==0)
            {
                a/=prm[j];
                cnt^=1;
            }
            if(cnt)b*=prm[j];
        }
        if(a!=1)b*=a;

        mp[b]++;
    }
    cin>>m;

    int ret1=0,ret2=0;
    for(auto i:mp)
    {
//        cout<<i.fi<<' '<<i.se<<endl;
        if(i.se%2==0)mmp[1]+=i.se;
        else mmp[i.fi]+=i.se;

        ret1=max(ret1,i.se);
    }
    for(auto i:mmp)
    {
        ret2=max(ret2,i.se);
    }
    while(m--)
    {
        ll a;cin>>a;
        if(a==0)
        {
            cout<<ret1<<endl;
        }
        else
        {
            cout<<ret2<<endl;
        }
    }
}
int main()
{
    for(int i=2;i*i<N;i++)if(!vis[i])
        for(int j=i*i;j<N;j+=i)vis[j]=1;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            prm.push_back(i);
        }
    }
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}