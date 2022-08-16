#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define REP(i,n) for(ll i=0;i<(n);i++)

struct quer{
    ll l,r,ind;
};

quer q[200005];
ll res[200005];
ll a[200005];
ll cnt[1000005];
ll n,m,block,curl = 0,curr = 0;
ll ans = 0;

bool cmp(quer q1, quer q2){
    if (q1.l/block != q2.l/block) return q1.l < q2.l;
    return q1.r < q2.r;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
	block = sqrt(n);
    REP(i,n) cin >> a[i];
	REP(i,m){
	   cin >> q[i].l >> q[i].r;
	    q[i].l --;
	    q[i].r --;
	    q[i].ind = i;
	}
	sort(q,q+m,cmp);
    REP(i,m){
        ll x = q[i].l;
        ll y = q[i].r;
        while (curl < x){
            ll in = a[curl];
            ans -= (2*cnt[in]-1)*in;
            cnt[in] --;
            curl ++;
        }
        while (curl > x){
            ll in = a[curl-1];
            ans += (2*cnt[in]+1)*in;
            cnt[in] ++;
            curl --;
        }
        while (curr <= y){
            ll in = a[curr];
            ans += (2*cnt[in]+1)*in;
            cnt[in] ++;
            curr ++;
        }
        while (curr > y+1){
            ll in = a[curr-1];n;
            ans -= (2*cnt[in]-1)*in;
            cnt[in] --;
            curr --;
        }
        res[q[i].ind] = ans;
    }
    REP(i,m) cout << res[i] << "\n";
}