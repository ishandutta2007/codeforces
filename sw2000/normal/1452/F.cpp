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
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
int n, q;
ll two[50], cnt[50], arr[50];

ll solve(int x, ll k)
{
    ll ret = 0;
    ll sum = 0, pre = 0;
    for(int i = 0; i < n; i++)
        cnt[i] = arr[i];
    for(int i = 0; i < n; i++)
        sum += cnt[i] * two[i];
    if(sum < k)
        return -1;
    for(int i = x + 1; i < n; i++)
        sum -= cnt[i] * two[i];
    for(int i = 0; i <= x; i++)
        pre += cnt[i];
    if(pre >= k)
        return 0;
    if(k > sum)
    {
        ll a = (k - sum - 1) / two[x] + 1;
        if(a % 2)
            a++;
        cnt[x] += a;
        for(int i = x + 1; i < n; i++)
        {
            a /= 2;
            ret += a;

            if(a <= cnt[i])
            {
                cnt[i] -= a;
                break;
            }
            else
            {
                a -= cnt[i];
                if(a % 2)
                {
                    a++;
                    cnt[i] = 1;
                }
                else
                {
                    cnt[i] = 0;
                }
            }
        }
    }
//    for(int i=0;i<n;i++)
//        cout<<cnt[i]<<' ';
//    cout<<endl;

    ll left = k;
    for(int i = 0; i <= x; i++)
        left -= cnt[i];
    ret += max(0ll, left);
    for(int i = x + 1; i < n && left >= two[i - x]; i++)
        if(cnt[i])
        {
            ll sub = min(left / two[i - x], cnt[i]);
            ret -= sub;
            left -= sub * two[i - x];
        }
    return ret;
}
int main()
{
    two[0] = 1;
    for(int i = 1; i < 50; i++)
        two[i] = two[i - 1] * 2;
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
//        int num=0;
    for(int i = 0; i < q; i++)
    {
        ll op, a, b;
        cin >> op >> a >> b;
        if(op == 1)
        {
            arr[a] = b;
        }
        else
        {
//            num++;
//            if(n==10&&q==100000)
//            {
//                if(num!=2831)continue;
//                else
//                {
//                    for(int j=0;j<n;j++)
//                    {
//                        cout<<arr[j]<<' ';
//                    }
//                    cout<<endl;
//                    cout<<a<<' '<<b<<endl;
//                }
//            }
            cout << solve(a, b) << endl;
        }
    }
    return 0;
}