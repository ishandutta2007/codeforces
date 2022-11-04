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
#define pii pair<int,int>
using namespace std;
const int maxn=200005;

int n,m,a[maxn],b[maxn];
double tmp;
int lis()
{
    b[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=b[len])
            b[++len]=a[i];
        else
        {
            int pos=upper_bound(b+1,b+len+1,a[i])-b;
            b[pos]=a[i];
        }
    }
    return len;
}
int main()
{
    sync;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>tmp;
    cout<<n-lis()<<endl;
}