#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000;

bitset<N>a, b[26], c, d; char s[N + 5], t[N + 5];
int main() {
	int n, q; scanf("%s", s), n = strlen(s);
	for(int i=0;i<n;i++) b[s[i] - 'a'][i] = 1, a[i] = 1;
	
	scanf("%d", &q);
	for(int i=1,opt,l,r,x;i<=q;i++) {
		scanf("%d", &opt);
		if( opt == 1 ) {
			scanf("%d%s", &x, t), x--;
			b[s[x] - 'a'][x] = 0, s[x] = t[0], b[s[x] - 'a'][x] = 1;
		} else {
			scanf("%d%d%s", &l, &r, t), l--, r--; int m = strlen(t);
			c = a, d = (a >> l) << l, d = ((d << (n - r - 1)) & a) >> (n - r - 1);
			for(int j=0;j<m;j++)
				c &= ((b[t[j] - 'a'] & d) >> j);
			printf("%d\n", c.count());
		}
	}
}