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
#define pi 3.141592653589
#define sqrt(x) sqrt(abs(x))

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
string s;
int g[100][3];
string name[100];

int main() {
	cin >> n;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		cin >> m >> name[i];
		for (int j = 0; j < m; j++) {
			cin >> s;
			int t = 2;
			if (s[0] == s[1] && s[1] == s[3] && s[3] == s[4] && s[4] == s[6] && s[6] == s[7]) t = 0; else
			if (s[0] > s[1] && s[1] > s[3] && s[3] > s[4] && s[4] > s[6] && s[6] > s[7]) t = 1;
			g[i][t]++;
		}
		a = max (a, g[i][0]);
		b = max (b, g[i][1]);
		c = max (c, g[i][2]);
	}
	printf ("If you want to call a taxi, you should call:");
	int f = 0;
	for (int i = 0; i < n; i++)
		if (g[i][0] == a) {
			if (f) printf (",");
			printf (" %s", name[i].c_str ());
			f = 1;
		}	
	printf (".\n");
	printf ("If you want to order a pizza, you should call:");
	f = 0;
	for (int i = 0; i < n; i++)
		if (g[i][1] == b) {
			if (f) printf (",");
			printf (" %s", name[i].c_str ());
			f = 1;
		}	
	printf (".\n");
	printf ("If you want to go to a cafe with a wonderful girl, you should call:");
	f = 0;
	for (int i = 0; i < n; i++)
		if (g[i][2] == c) {
			if (f) printf (",");
			printf (" %s", name[i].c_str ());
			f = 1;
		}	
	printf (".\n");
        return 0;
}