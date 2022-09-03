#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
int m;
vi ans;
set<ii> all;
int l[1000], r[1000];
int was[1000];

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &l[i], &r[i]);
		if (l[i] > r[i]) swap (l[i], r[i]);
		all.insert (mp (r[i], l[i]));
	}
	while (!all.empty ()) {
		int x = all.begin ()->first;
		ans.pb (x);
		for (int i = 0; i < n; i++)
			if (!was[i] && l[i] <= x && r[i] >= x) {
				all.erase (mp (r[i], l[i]));
				was[i] = 1;
			}
	}
	printf ("%d\n", ans.size ());
	for (int i = 0; i < ans.size (); i++)
		printf ("%d ", ans[i]);
	printf ("\n");	
	return 0;
}