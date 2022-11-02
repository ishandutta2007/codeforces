#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 400000;
int a[MAXN + 5], s[MAXN + 5], cnt;
pii b[MAXN + 5];

int tag[MAXN + 5];

vector<int>v[MAXN + 5];
void print(int A, int B) {
	for(int i=1;i<=A;i++) {
		v[i].push_back(0);
		for(int j=1;j<=B;j++)
			v[i].push_back(0);
	}
	for(int i=1;i<=cnt;i++)
		if( b[i].first > A ) b[i].first = A;
	int x = 1, y = 1, nw = 1;
	for(int i=cnt;i>=1;i--) {
		for(int p=1;p<=b[i].first;p++) {
			v[x][y] = b[i].second;
			x++, y++;
			if( x > A ) {
				nw++;
				if( nw > B ) {
					for(int i=1;i<=A;i++)
						for(int j=1;j<=B;j++)
							printf("%d%c", v[i][j], (j == B ? '\n' : ' '));
					return ;
				}
				x = 1, y = nw;
			}
			if( y > B ) y = 1;
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int nw = 1;
	for(int i=2;i<=n;i++) {
		if( a[i] == a[i-1] ) nw++;
		else b[++cnt] = make_pair(nw, a[i-1]), nw = 1;
	}
	b[++cnt] = make_pair(nw, a[n]);
	sort(b + 1, b + cnt + 1);
	for(int i=1;i<=cnt;i++)
		s[i] = s[i-1] + b[i].first;
	for(int i=1;i<=n;i++)
		tag[i] = -1;
	for(int i=1;i<=n;i++) {
		int p = upper_bound(b + 1, b + cnt + 1, make_pair(i, -1)) - b - 1;
		int tot = s[p] + (cnt - p) * i;
		int lim = n / i;
		for(int j=i;j<=lim;j++) {
			int x = i * j;
			if( x <= tot ) tag[x] = i;
		}
	}
	for(int i=n;i>=1;i--) {
		if( tag[i] != -1 ) {
			printf("%d\n%d %d\n", i, tag[i], i/tag[i]);
			print(tag[i], i/tag[i]);
			return 0;
		}
	}
}