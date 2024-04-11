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
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,k,arr[maxn],brr[maxn];
int s[maxn];
int main()
{
//    freopen("in.txt","r",stdin);
    vector<vi>ans;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
    for(int i=1;i<=k;i++)scanf("%d",brr+i);
    sort(arr,arr+n,greater<int>());
    for(int i=0;i<n;i++)
    {
        int p=upper_bound(s,s+ans.size()+1,brr[arr[i]],greater<int>())-s;

        if(p==ans.size())ans.push_back({arr[i]});
        else ans[p].push_back(arr[i]);
        s[p]++;
    }

    printf("%d\n",ans.size());
    for(auto i:ans)
    {
        printf("%d ",i.size());
        for(auto j:i)printf("%d ",j);
        puts("");
    }
    return 0;
}