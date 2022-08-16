#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)

struct quer{
    int l,r,ind;
};

quer q[100005];
int res[100005];
int a[100005];
int cnt[100005];
int n,m,block,curl = 0,curr = 0;
int ans = 0,x,y,in;

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
        x = q[i].l;
        y = q[i].r;
        while (curl < x){
            in = a[curl];
            curl ++;
            if (in > n) continue;
            if (cnt[in] == in) ans --;
            cnt[in] --;
            if (cnt[in] == in) ans ++;
        }
        while (curl > x){
            in = a[curl-1];
            curl --;
            if (in > n) continue;
            if (cnt[in] == in) ans --;
            cnt[in] ++;
            if (cnt[in] == in) ans ++;
        }
        while (curr <= y){
            in = a[curr];
            curr ++;
            if (in > n) continue;
            if (cnt[in] == in) ans --;
            cnt[in] ++;
            if (cnt[in] == in) ans ++;
        }
        while (curr > y+1){
            in = a[curr-1];n;
            curr --;
            if (in > n) continue;
            if (cnt[in] == in) ans --;
            cnt[in] --;
            if (cnt[in] == in) ans ++;
        }
        res[q[i].ind] = ans;
    }
    REP(i,m) cout << res[i] << "\n";
}