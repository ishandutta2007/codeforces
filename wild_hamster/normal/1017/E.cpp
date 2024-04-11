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
#define ROW 5
#define IN 5
#define OR 10
#define AND 15
#define XOR 20
#define NOT 25
typedef long long ll;
using namespace std;
ll n,i,j,k,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
ll z[500500], as[500500], bs[500500];
vector<pair<ll, pii> > s;
struct pt {
	ll x, y;
	pt(ll x, ll y) {
	    this->x = x;
	    this->y = y;
	}
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

ll area(vector<pt> &a) {
    ll sz = a.size();
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += (a[i].x + a[(i+1)%sz].x)*(a[i].y - a[(i+1)%sz].y);
    }
    return ans;
}

ll dist(pt a, pt b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

vector<pt> a, b;

void z_function () {
	int n = (int) s.size();
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, (int)z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
}

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        a.push_back(pt(x, y));
    }
    for (int i = 0; i < m; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        b.push_back(pt(x, y));
    }
    convex_hull(a);
    convex_hull(b);
    if (area(a) != area(b) || a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }
    as[0] = bs[0] = 1;
    ll n = a.size();
    s.clear();
    for (int i = 0; i < n; i++) {
        pt p1 = a[i];
        pt p2 = a[(i+1)%n];
        pt p3 = a[(i+2)%n];
        vector<pt> tmp;
        tmp.push_back(p1);
        tmp.push_back(p2);
        tmp.push_back(p3);
        ll S = area(tmp);
        ll a1 = dist(p1, p2);
        ll a2 = dist(p2, p3);
        s.push_back(mp(S, mp(a1, a2)));
    }

    for (int i = 0; i < n; i++) {
        pt p1 = b[i];
        pt p2 = b[(i+1)%n];
        pt p3 = b[(i+2)%n];
        vector<pt> tmp;
        tmp.push_back(p1);
        tmp.push_back(p2);
        tmp.push_back(p3);
        ll S = area(tmp);
        ll a1 = dist(p1, p2);
        ll a2 = dist(p2, p3);
        s.push_back(mp(S, mp(a1, a2)));
    }
    z_function();
    for (int i = n; i < 2*n; i++) {
        if (z[i] == 2*n-i) {
            as[2*n-i] = 1;
        }
    }

    s.clear();


    for (int i = 0; i < n; i++) {
        pt p1 = b[i];
        pt p2 = b[(i+1)%n];
        pt p3 = b[(i+2)%n];
        vector<pt> tmp;
        tmp.push_back(p1);
        tmp.push_back(p2);
        tmp.push_back(p3);
        ll S = area(tmp);
        ll a1 = dist(p1, p2);
        ll a2 = dist(p2, p3);
        s.push_back(mp(S, mp(a1, a2)));
    }

    for (int i = 0; i < n; i++) {
        pt p1 = a[i];
        pt p2 = a[(i+1)%n];
        pt p3 = a[(i+2)%n];
        vector<pt> tmp;
        tmp.push_back(p1);
        tmp.push_back(p2);
        tmp.push_back(p3);
        ll S = area(tmp);
        ll a1 = dist(p1, p2);
        ll a2 = dist(p2, p3);
        s.push_back(mp(S, mp(a1, a2)));
    }
    z_function();
    for (int i = n; i < 2*n; i++) {
        if (z[i] == 2*n-i) {
            bs[2*n-i] = 1;
        }
    }
    for (int i = 0; i <= n; i++)
    if (as[i] && bs[n-i]) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}