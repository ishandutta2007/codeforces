#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
const ll INF = (1LL<<60);
struct node{
	int pos; ll key;
	friend bool operator < (node a, node b) {
		return a.key < b.key;
	}
}a[MAXN + 5], b[3*MAXN + 5];
ll sum[3*MAXN + 5];
int res[MAXN + 5];
int n; ll m;
int main() {
	scanf("%lld%d", &m, &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i].key), a[i].pos = i;
	sort(a + 1, a + n + 1);
	a[n + 1].key = INF;
	for(int i=1;i<=n;i++)
		scanf("%d", &b[i].key), b[i].pos = i;
	sort(b + 1, b + n + 1);
	for(int i=1;i<=n;i++) {
		b[2*n + i] = b[n + i] = b[i];
		b[i].key -= m, b[2*n + i].key += m;
	}
	int p = 1;
	for(int i=1;i<=n;i++) {
		while( b[p].key <= a[i].key ) p++;
		sum[0] += a[i].key;
		if( p - i + 1 <= 2*n + 1 )
			sum[p - i + 1] -= 2*a[i].key;
	}
	p = 1;
	for(int i=1;i<=3*n;i++) {
		while( a[p].key < b[i].key ) p++;
		sum[max(0, i - n + 1)] -= b[i].key;
		if( i - p + 2 <= 2*n + 1 )
			sum[i - p + 2] += 2*b[i].key;
		sum[min(i + 1, 2*n + 2)] -= b[i].key;
	}
	int ans = 1;
	for(int i=1;i<=2*n+1;i++) {
		sum[i] += sum[i-1];
		if( sum[i] < sum[ans] )
			ans = i;
	}
	for(int i=1;i<=n;i++)
		res[a[i].pos] = b[ans+i-1].pos;
	printf("%lld\n", sum[ans]);
	for(int i=1;i<=n;i++)
		printf("%d ", res[i]);
}