#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=200005;
string s;
int a[200005],v[1000005];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
    mm(v);
    int n,k,d;
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    int ss=99999999;
    for(int i=1;i<=d;i++)
    {
        if(v[a[i]]==0)
        {
            sum++;
        }
        v[a[i]]++;
    }
    ss=min(sum,ss);
    for(int i=d+1;i<=n;i++)
    {
        v[a[i-d]]--;
        if(v[a[i-d]]==0)
            sum--;
        if(v[a[i]]==0)
        {
            sum++;
        }
        v[a[i]]++;
        ss=min(sum,ss);
    }
    cout<<ss<<endl;
    }
    return 0;
}