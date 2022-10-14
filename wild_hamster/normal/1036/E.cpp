#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,y, x, t, z, tot;
string s;
struct seg {
    ll x1, y1, x2, y2;
} a[1005];
ll gcd(ll a, ll b) {
    return b==0?a:gcd(b, a%b);
}
ll count_points(seg s) {
    ll x = s.x2 - s.x1;
    ll y = s.y2 - s.y1;
    if (x < 0)
        x =-x;
    if (y < 0)
        y =-y;
    ll g = gcd(x, y);
    return g+1;
}
struct pt {
	ll x, y;
	pt(ll x, ll y) {
	    this->x = x;
	    this->y = y;
	}
};

inline ll area (pt a, pt b, pt c) {
	return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)>0?1
         :(b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)<0?-1:0);
}

inline bool intersect_1 (ll a, ll b, ll c, ll d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}

ll Abs(ll x) {
    return x>0?x:-x;
}
set<pair<pii, ll> > f;
set<pii> ff;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        ans += count_points(a[i]);
    }
    //cout << ans << endl;

    for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++) {
        seg seg1 = a[i];
        seg seg2 = a[j];
        pt pt1 = pt(seg1.x1, seg1.y1);
        pt pt2 = pt(seg1.x2, seg1.y2);
        pt pt3 = pt(seg2.x1, seg2.y1);
        pt pt4 = pt(seg2.x2, seg2.y2);
        if (!intersect(pt1, pt2, pt3, pt4)) {
            continue;
        }
        pt hyu = pt(pt2.x-pt1.x, pt2.y-pt1.y);
        ll l = 0, r = gcd(Abs(hyu.x), Abs(hyu.y));
        hyu.x /= r;
        hyu.y /= r;
        while (l < r) {
            ll mid = (l+r+1)/2;
            pt midpt = pt(pt1.x + hyu.x*mid, pt1.y+hyu.y*mid);
            if (intersect(midpt, pt2, pt3, pt4)) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        pt midpt = pt(pt1.x + hyu.x*l, pt1.y+hyu.y*l);
        if (intersect(midpt, midpt, pt3, pt4)) {
            f.insert(mp(mp(midpt.x, midpt.y), i));
            f.insert(mp(mp(midpt.x, midpt.y), j));
            ff.insert(mp(midpt.x,midpt.y));
        }
    }
    cout << ans-f.size()+ff.size() << endl;

	return 0;
}