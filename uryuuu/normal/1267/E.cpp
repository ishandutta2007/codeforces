#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define Debug(in) cout<<#in<<"="<<(in)<<endl
#define mm(a,x) memset(a,x,sizeof(a))
#define mkp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f,mod=1e9+7;
const int N=105;
int n,m;
int a[N][N];
pii b[N];
vector<int>ans;
int main(void)
{
    sync;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    int res=inf;
    for(int i=1;i<n;++i)
    {
        int si=0,sn=0;
        for(int j=1;j<=m;++j)
        {
            si+=a[j][i];
            sn+=a[j][n];
            b[j].first=a[j][i]-a[j][n];
            b[j].second=j;
        }
        sort(b+1,b+1+m);
        int d=sn-si;
        if(d<=0)
        {
            res=0;
            ans.clear();
            continue;
        }
        vector<int>v;
        for(int j=1;j<=m;++j)
        {
            d+=b[j].first;
            v.push_back(b[j].second);
            if(d<=0)
            {
                if(res>j)
                {
                    res=j;
                    swap(v,ans);
                }
                break;
            }
        }
    }
    cout<<res<<endl;
    for(int x:ans) cout<<x<<" ";
    return 0;
}
//
//Think TWICE, Code ONCE!