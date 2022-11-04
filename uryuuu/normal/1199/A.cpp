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
#define inf 0x3f3f3f3f
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
const ll Mod=998244353;
#define maxn 105
using namespace std;
int a[100010];
int main()
{
    sync
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int ff=0,fff=0;
        if(i-x<=0)
        {
            for(int j=1;j<i;j++)
                if(a[j]<=a[i])
                {
                    ff=1;
                    break;
                }
        }
        else
        {
            for(int j=i-x;j<i;j++)
                if(a[j]<=a[i])
                {
                    ff=1;
                    break;
                }
        }
        if(i+y>n)
        {
            for(int j=i+1;j<=n;j++)
                if(a[i]>=a[j])
                {
                    fff=1;
                    break;
                }
        }
        else
        {
            for(int j=i+1;j<=i+y;j++)
                if(a[i]>=a[j])
                {
                    fff=1;
                    break;
                }
        }
        if(ff==0&&fff==0)
        {
        cout<<i<<endl;
        break;
        }
    }
    return 0;
}