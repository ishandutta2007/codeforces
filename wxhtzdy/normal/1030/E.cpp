#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define mod 998244353
#define xx first
#define yy second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ll long long
#define pii pair<int,int>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;/// find_by_order(x)(x+1th) , order_of_key() (strictly less)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());


int n;
int niz[300005];
int cnt[2];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    ff(i,1,n){
        ll x;
        cin >> x;
        ff(j,0,60)if(x&(1LL<<j))niz[i]++;
    }
    int sum = 0;
    ll ans = 0;
    cnt[0] = 1;
    fb(i,n,1){
        sum += niz[i];
        int tmp = 0;
        int mx = 0;
        ff(j,0,61){
            if(i + j > n)break;
            tmp += niz[i + j];
            mx = max(mx, niz[i + j]);
            if(2 * mx > tmp && tmp % 2 == 0)ans--;
        }
        ans += cnt[sum%2];
        cnt[sum%2]++;
    }
    cout << ans;
    return 0;
}