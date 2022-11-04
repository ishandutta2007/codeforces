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
const int maxn=500005;
int a[100005],b[100005],c[100005],r[100005],e[100005];
int main()
{
    sync
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]]=i;
    }
    int d;
    for(int i=1;i<=n;i++)
    {
        cin>>d;
        c[i]=b[d];
    }
    for(int i=1;i<=n;i++)
        e[i]=c[n-i+1];
//    for(int i=1;i<=n;i++)
//        cout<<e[i];
    r[0]=10000000;
    for(int i=1;i<=n;i++)
    {
        r[i]=min(r[i-1],e[i]);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
       if(e[i]>r[i-1])
           sum++;
    }
    cout<<sum<<endl;
    return 0;
}