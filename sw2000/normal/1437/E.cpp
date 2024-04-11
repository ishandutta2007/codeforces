#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int n, m, arr[N], brr[N];
int dp[N];
int f(int l, int r)
{
//    cout<<arr[l]<<' '<<arr[r]<<endl;
    int tot = 0;
    for(int i = l + 1; i < r; ++i)
        if(arr[l] <= arr[i] && arr[i] <= arr[r])
        {
            int p = upper_bound(dp, dp + tot, arr[i])-dp;

            if(p == tot)
                tot++;
            dp[p]=arr[i];
        }
//    cout<<r-l-1-tot<<endl;
    return r - l - 1 - tot;
}
int solve()
{
    for(int i = 2; i <= m; i++)
    {
        if(arr[brr[i]] < arr[brr[i - 1]])
            return -1;
    }
    int ret = 0;
    for(int i = 0; i <= m; i++)
        ret += f(brr[i], brr[i + 1]);
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] -= i;
    }
    arr[0] = -inf;
    arr[n + 1] = inf;
    for(int i = 1; i <= m; i++)
        cin >> brr[i];
    brr[m + 1] = n + 1;
    cout << solve() << endl;
    return 0;
}