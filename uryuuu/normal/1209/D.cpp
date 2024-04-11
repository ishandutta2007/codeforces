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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int  maxn=100005;

int father[100005];
map<pair<int,int>,int>mp;

int getf(int x)
{
    if(x==father[x])
        return x;
    return father[x]=getf(father[x]);
}

void jihe(int x,int y)
{
    x=getf(x);
    y=getf(y);
    father[y]=father[x];
}

int main()
{
    sync
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        father[i]=i;
    }
    int a,b;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        cin>>a>>b;
        if(getf(a)!=getf(b))
        {
            sum++;
            jihe(a,b);
        }
    }
    cout<<k-sum<<endl;
    return 0;
}