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
const int maxn = 100 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int arr[maxn],brr[maxn];

int main()
{
    // freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",arr+i);
        for(int i=0;i<n;i++)scanf("%d",brr+i);
        sort(arr,arr+n);
        sort(brr,brr+n);
        for(int i=0;i<n;i++)printf("%d ",arr[i]);
        puts("");
        for(int i=0;i<n;i++)printf("%d ",brr[i]);
        puts("");
    }
    return 0;
}