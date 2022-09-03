#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define mp make_pair

typedef pair<int, int> ii;

int n, a, b, ky;
set<ii> f[200001];
int t[200001], x[200001], y[200001], z[200001];
ii ay[200001];
set<ii>::iterator it;
char w[10];

int add (int x, int y, int Y, int d) {
        ii cur = mp (x, y);
        for (; Y <= 200000; Y |= Y + 1)
                if (d == 0) f[Y].insert (cur); else f[Y].erase (cur);
}

ii get (int x, int y, int Y) {
        ii cur = mp (2e9, 2e9);
        for (; Y > 0; Y = (Y & (Y + 1)) - 1) 
        	if (f[Y].size () > 0) {
	                it = f[Y].lower_bound (mp (x, y));
        	        if (it != f[Y].end () && *it < cur) cur = *it;
	        }
        return cur;
}

int main () {
	scanf ("%d\n", &n);
        for (int i = 0; i < n; i++) {
        	scanf ("%s%d%d\n", w, &a, &b);
                t[i] = w[0] == 'a' ? 0 : w[0] == 'r' ? 1 : 2;
                x[i] = a + int (t[i] == 2);
                y[i] = b + int (t[i] == 2);
                ay[i] = mp (-y[i], i);
        }
        sort (ay, ay + n);
        int r = 0;
        for (int i = 0; i < n; i++) {
        	if (i == 0 || ay[i].first != ay[i - 1].first) r++;
        	z[ay[i].second] = r;
        }
        for (int i = 0; i < n; i++)
                if (t[i] == 2) {
                        ii res = get (x[i], y[i], z[i]);
                        if (res.first > 1.5e9) printf ("%d\n", -1); else printf ("%d %d\n", res.first, res.second);
                } else add (x[i], y[i], z[i], t[i]);
        return 0;
}