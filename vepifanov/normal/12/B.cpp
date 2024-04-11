#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char a[100], b[100];

int main() {
	gets (a);
	gets (b);
	int n = strlen (a);
	for (int i = 0; i < n; i++)
		if (a[i] != '0' && a[i] < a[0]) swap (a[i], a[0]);
	sort (a + 1, a + n);
	if (strcmp (a, b) == 0) printf ("OK\n"); else printf ("WRONG_ANSWER\n");
	return 0;
}