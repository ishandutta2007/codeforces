#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;

int n, k, arr[N], brr[N], rk[N];
ll solve()
{
    set<int>s;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        rk[arr[i]] = i;
        s.insert(i);
    }

    for(int i = 1; i <= k; i++)
    {
        cin >> brr[i];
        brr[i] = rk[brr[i]];
        s.erase(brr[i]);
//        cout << brr[i] << ' ';
    }
    ll ret = 1;
    for(int i = 1; i <= k; i++)
    {
        int cnt = 0;
        if(s.count(brr[i] + 1))
            cnt++;
        if(s.count(brr[i] - 1))
            cnt++;
        ret = ret * cnt % mod;
        s.insert(brr[i]);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;
    cin >> _;
    while(_--)
        cout << solve() << endl;
    return 0;
}