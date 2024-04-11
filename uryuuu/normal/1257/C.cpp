#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
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
const ll Mod=1e9+7;
int a[200005],v[200005];
int main()
{
    int t,x,y;
    cin>>t;
    int n;
    int f=0;
    int zx;
    while(t--)
    {
        f=0;
        scanf("%d",&n);
        zx=20000000;
        for(int i=1;i<=n;i++)
        {
            v[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(v[a[i]])
                zx=min(i-v[a[i]]+1,zx);
            v[a[i]]=i;
        }
        if(zx==20000000)
            cout<<-1<<endl;
        else
            cout<<zx<<endl;
    }
    
    return 0;
}