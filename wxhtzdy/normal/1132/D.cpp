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



int n,k;
ll a[200005];
int b[200005];
ll cnt[200005];

bool check(ll r){
    priority_queue<pair<ll, int>> pq;
    ff(i,1,n){
        pq.push({-(a[i] / b[i] + 1), i});
        cnt[i] = 0;
    }
    ff(i,1,k){
        auto x = pq.top();
        pq.pop();
        if(-x.xx < i)return false;
        cnt[x.yy]++;
        pq.push({-((a[x.yy] + cnt[x.yy] * r) / b[x.yy] + 1), x.yy});
    }
    if(-pq.top().first<k)return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    ff(i,1,n)cin >> a[i];
    ff(i,1,n)cin >> b[i];
    ll low = 0, high = 1e13, ans = -1;
    while(low <= high){
        ll mid = (low + high) / 2;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans;
    return 0;
}