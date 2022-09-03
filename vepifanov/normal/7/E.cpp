#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;

char w[200];
map<string, int> all;
int mmask[200], msusp[200];
vector<int> v;
string l;
int amask;

int calc (int a, int b) {
	vector<int> v;
	v.clear ();
	int last = -1, mask = 0, susp = 0, d = 0;
	string cur = "";
	for (int j = a; j <= b; j++) {
			if (j < b && (l[j] >= 'a' && l[j] <= 'z' || l[j] >= 'A' && l[j] <= 'Z' || l[j] >= '0' && l[j] <= '9')) cur += l[j]; else {
			if (cur != "") {
				if (d == 0) {
					int t = -1, cmask = 0, csusp = 0; 
					if (all.find (cur) != all.end ()) { t = all[cur]; cmask = mmask[t]; csusp = msusp[t]; }
					susp |= csusp;
					v.push_back (cmask);
				}
				cur = "";
                	}
		}
		if (j == b) break;
		if (l[j] == '(') {
			if (d == 0) last = j + 1;
			d++;
		}
		if (l[j] == ')') {
			d--;
			if (!d) {
				susp |= calc (last, j);
				v.push_back (0);
			}
		}
		if (d == 0 && l[j] == '+') v.push_back (0);
		if (d == 0 && l[j] == '-') v.push_back (1);
		if (d == 0 && l[j] == '*') v.push_back (2);
		if (d == 0 && l[j] == '/') v.push_back (3);
	}
	for (int j = 1; j < v.size (); j+= 2) {
		mask |= 1 << v[j];
		if (v[j] == 1 && (v[j + 1] & 3)) susp = 1;
		if (v[j] == 2 && ((v[j - 1] & 3) || (v[j + 1] & 3))) susp = 1;
		if (v[j] == 3 && ((v[j - 1] & 3) || v[j + 1])) susp = 1;
	}
	if (mask & 3) mask &= 3;
	amask = mask;
	return susp;
}

int main() {
        int n;
        scanf ("%d\n", &n);
        for (int i = 0; i <= n; i++) {
		string s, ss;
        	gets (w);
		istringstream in(w);
		if (i < n) {
			in >> s;
			if (s.size () == 1) in >> s;
			in >> s;
		}
		l = "";
		while (in >> ss) l += ss;
		msusp[i] = calc (0, l.size ());
		mmask[i] = amask;
		if (i < n) all[s] = i;
        }
	if (msusp[n]) printf ("Suspicious\n"); else printf ("OK\n");
	return 0;
}