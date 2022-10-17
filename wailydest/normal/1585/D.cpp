#include <cstdio>
#include <cstring>

const int N = 500000;
int t, n, a[N];
bool b[N], u[N];

void add(int i) 
{
	while (i < n) {
		b[i] = !b[i];
		i |= i + 1;
	}
}

bool get(int i) 
{
	bool s = 0;
	while (i >= 0) {
		s = s != b[i];
		i = (i & i + 1) - 1;
	}
	return s;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(b, 0, n);
		memset(u, 0, n);
		bool s = 0, yes = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			--x;
			if (u[x]) yes = 1;
			u[x] = 1;
			s = s != (get(x) != (i & 1));
			add(x);
		}
		printf(!s || yes ? "YES\n" : "NO\n");
	}
	return 0;
}