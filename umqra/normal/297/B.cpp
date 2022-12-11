#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair
        

const int N = (int)1e5 + 100;
set <pii> t;
int a[N], b[N];


int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int s = 0; s < m; s++)
		scanf("%d", &b[s]);
	sort(a, a + n);
                        
	for (int i = 0; i < m; i++)
		t.insert(mp(b[i], i));

	for (int i = 0; i < n; i++)
	{
		if (t.lower_bound(mp(a[i], 0)) == t.end())
		{                      
			puts("YES");
			return 0;
		}
		else
		{
			set<pii>::iterator it = t.lower_bound(mp(a[i], 0));
			t.erase(it);
		}
	}

	puts("NO");
	return 0;
}