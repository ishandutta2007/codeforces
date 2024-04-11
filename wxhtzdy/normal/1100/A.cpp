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

int n, k;
int niz[105];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    ff(i,0,n - 1){
        cin >> niz[i];
    }
    int ans = 0;
    ff(i,0,k - 1){
        int sum = 0;
        ff(j,0,n - 1){
            if(j % k != i)sum += niz[j];
        }
        ans = max(ans, abs(sum));
    }
    cout << ans << "\n";
}