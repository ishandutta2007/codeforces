#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define xx first
#define yy second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>



using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;

ll lcm(ll x, ll y){
    return x * y / __gcd(x, y);
}

int main()
{

    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    if(n == 1)cout << 1;
    else{
        if(n == 2)cout << 2;
        else{
            if(n == 3)cout << 6;
            else{
                if(n % 2 == 1)cout << n * (n - 1) * (n - 2);
                else{
                    ll ans = 0;
                    ff(i,0,50){
                        ff(j,0,50){
                            ff(k,0,50){
                                ll x = n - i, y = n - j, z = n - k;
                                if(x <= 0 || y <= 0 || z <= 0)continue;
                                ans = max(ans, lcm(x, lcm(y, z)));
                            }
                        }
                    }
                    cout << ans;
                }
            }
        }
    }
    return 0;
}