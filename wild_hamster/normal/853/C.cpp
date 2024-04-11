#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
vector<ll> t[800500];
ll a[200500];
void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = vector<int> (1, a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		merge (t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
			back_inserter (t[v]));
	}
}

int query (int v, int tl, int tr, int l, int r, int x, int y) {
	if (l > r)
		return 0;
	if (l == tl && tr == r) {
		int pos = upper_bound (t[v].begin(), t[v].end(), y) - upper_bound(t[v].begin(), t[v].end(), x-1);
		return pos;
	}
	int tm = (tl + tr) / 2;
	return query (v*2, tl, tm, l, min(r,tm), x, y) +
		query (v*2+1, tm+1, tr, max(l,tm+1), r, x, y);
}
long long f(ll x)
{
    return (1LL*x*(x-1)/2);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x);
        a[i] = x-1;
    }
    build(1, 0, n-1);
    for (i = 0; i < m; i++)
    {
        ll x1, y1, x2, y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1--;x2--;y1--;y2--;
        long long ans = f(n-1-x2) + f(x1) + f(n-1-y2) + f(y1);
        ll tmp = query(1, 0, n-1, 0, x1-1, 0, y1-1);
        ans -= f(tmp);
        tmp = query(1, 0, n-1, 0, x1-1, y2+1, n-1);
        ans -= f(tmp);
        tmp = query(1, 0, n-1, x2+1, n-1, 0, y1-1);
        ans -= f(tmp);
        tmp = query(1, 0, n-1, x2+1, n-1, y2+1, n-1);
        ans -= f(tmp);
        ans = f(n) - ans;
        printf("%I64d\n", ans);
    }
    return 0;
}