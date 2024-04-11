#define _CRT_SECURE_NO_WARNINGS

#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <complex>
#include <hash_map>
#include <hash_set>

using namespace std;

#define pb push_back
#define pob pop_back
#define itr iterator
#define rs resize
#define as assign
#define fs first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define mp make_pair
#define sz(a) (int)a.size()
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FOD(i, n) for (int i = n - 1; i >= 0; --i)

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <string> vs;
typedef vector <vs> vvs;
typedef vector <char> vc;
typedef vector <vc> vvc;
typedef vector <vvc> vvvc;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvl> vvvl;
typedef vector <vvvl> vvvvl;
typedef vector <vvb> vvvb;
typedef double db;
typedef long double ldb;
typedef vector <db> vdb;
typedef vector <vdb> vvdb;
typedef vector <vvdb> vvvdb;
typedef vector <ldb> vldb;
typedef pair <int, int> ii;
typedef pair <int, char> ic;
typedef pair <ll, ll> lll;
typedef pair <int, ll> il;
typedef pair <ll, int> li;
typedef vector <ii> vii;
typedef vector <ic> vic;
typedef vector <vic> vvic;
typedef vector <vii> vvii;
typedef vector <lll> vll;
typedef vector <vll> vvll;
typedef pair <ll, int> li;
typedef pair <ll, ll> lll;
typedef pair <int, ll> il;
typedef set <int> si;
typedef set <ll> sl;
typedef set <li> sli;
typedef set <il> sil;                                     
typedef set <lll> sll;
typedef set <ii> sii;
typedef set <pair <int, bool> > sib;
typedef vector <si> vsi;
typedef vector <sii> vsii;
typedef map <int, int> mii;
typedef map <string, int> msi;
typedef map <string, char> msc;
typedef map <char, int> mci;
typedef queue <int> qi;
typedef deque <int> di;
typedef stack <int> sti;

const db inf = 1e9 + 7;
const ldb eps = 1e-6;   
const int M = 100;
const int N = 100005;

struct pt
{
    ldb x, y;
    pt() { }
    pt(ldb x, ldb y) : x(x), y(y) { }
};

struct lin
{
    ldb a, b, c;
    lin() { }   
    lin(ldb a, ldb b, ldb c) : a(a), b(b), c(c) { }
};

pt vec(pt a, pt b)
{
    return pt(b.x - a.x, b.y - a.y);
}

lin line(pt a, pt b)
{
    return lin(a.y - b.y, b.x - a.x, a.x * b.y - a.y * b.x);
}

pt ins(lin q, lin t)
{
    if (fabs(q.a * t.b - q.b * t.a) < eps * eps)
        return pt(1e20, 1e20);                     
    return pt((q.b * t.c - q.c * t.b) / (q.a * t.b - q.b * t.a), ((t.a * q.c - t.c * q.a) / (q.a * t.b - q.b * t.a)));
}

db dis(pt a, pt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

db sq(pt a, pt b, pt c)
{
    return fabs((a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x)) / 2;
}

int sign(pt a) {
	if (a.y == 0 && a.x > 0) {
		return 1;
	}

	if (a.y > 0) {
		return 2;
	}

	if (a.y == 0 && a.x < 0) {
		return 3;
	}

	if (a.y < 0) {
		return 4;
	}

	assert(false);
	return 0;
}

bool ls(pt a, pt b)
{
    if (sign(a) != sign(b)) {
		return sign(a) < sign(b);
	}

	return b.x * a.y - b.y * a.x > 0;
}

int main()
{        
    ldb w, h, a;
    cin >> w >> h >> a;
    ldb r = sqrt(w * w + h * h) / 2;
    ldb al = atan(h / w);
    ldb pi = acos(-1.0);    
    a *= pi / 180;
    if (a > pi / 2)
        a = pi - a;
    pt t[4], v[4];
    t[0] = pt(r * cos(a - al), r * sin(a - al));
    t[1] = pt(r * cos(a + al), r * sin(a + al));
    t[2] = pt(r * cos(a - al + pi), r * sin(a - al + pi));
    t[3] = pt(r * cos(a + al + pi), r * sin(a + al + pi));
    lin q[4], g[4];
    for (int i = 0; i < 4; ++i)
        q[i] = line(t[i], t[(i + 1) % 4]);
    v[0] = pt(w / 2, h / 2);
    v[1] = pt(-w / 2, h / 2);
    v[2] = pt(-w / 2, -h / 2);
    v[3] = pt(w / 2, -h / 2);
    for (int i = 0; i < 4; ++i)
        g[i] = line(v[i], v[(i + 1) % 4]);
    vector <pt> con;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            pt d = ins(q[i], g[j]);
            if (!(fabs(d.x - 1e20) < eps && fabs(d.y - 1e20) < eps) && d.x < w / 2 + eps && d.y < h / 2 + eps && d.x > -w / 2 - eps && d.y > -h / 2 - eps)
                con.pb(d);
        }
    ldb s = 0.0;
    sort(con.begin(), con.end(), ls);
    for (int i = 1; i < sz(con); ++i)
        s += sq(con[0], con[i - 1], con[i]);
  printf("%.10Lf", s);
    return 0;         
}