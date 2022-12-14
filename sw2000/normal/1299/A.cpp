#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int sum[35],arr[maxn];
 
int main()
{
    // freopen("in.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        int tmp=arr[i];
        for(int j=0;tmp;j++)
        {
            sum[j]+=tmp&1;
            tmp>>=1;
        }
    }
    int id=-1;//
    for(int i=0;i<35;i++)
        if(sum[i]==1)id=i;
    if(~id)for(int i=0;i<n;i++)
        if(arr[i]&1<<id)swap(arr[0],arr[i]);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}