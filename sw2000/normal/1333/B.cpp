#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int arr[maxn],brr[maxn];
bool solve()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
    for(int i=0;i<n;i++)scanf("%d",brr+i);
    bool f1=0,f2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<brr[i]&&f2==0||arr[i]>brr[i]&&f1==0)return 0;
        if(arr[i]==-1)f1=1;
        else if(arr[i]==1)f2=1;
    }
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("YES");
        else puts("NO");
    }
    return 0;
}