#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

bool tag[MAXN + 5];
int a[MAXN + 5], b[8], f[1<<8], g[1<<8], bts[1<<8];
int a2[MAXN + 5], b2[8];

vector<int>v1[2*MAXN + 5], v2[2*MAXN + 5];
int d[2*MAXN + 5];

int L[MAXN + 5], R[MAXN + 5], n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int dcnt = 0; d[0] = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d%d", &L[i], &R[i]), L[i]--;
		d[++dcnt] = L[i], d[++dcnt] = R[i];
	}
	d[++dcnt] = m;
	sort(d, d + dcnt + 1), dcnt = unique(d, d + dcnt + 1) - d - 1;
	for(int i=1;i<=n;i++) {
		L[i] = lower_bound(d, d + dcnt + 1, L[i]) - d;
		R[i] = lower_bound(d, d + dcnt + 1, R[i]) - d;
		v1[L[i]].push_back(i), v2[R[i]].push_back(i);
	}
	for(int i=1;i<(1<<k);i++) bts[i] = bts[i >> 1] + (i & 1);
	
	int p = 0, t = 1;
	for(int i=0;i<=dcnt;i++) {
		for(int s=0;s<t;s++) g[s] = f[s];
		for(int j=0;j<(int)v2[i].size();j++) tag[v2[i][j]] = true;
		int cnt = 0, t2;
		for(int j=0;j<p;j++)
			if( !tag[b[j]] ) b2[cnt++] = b[j];
		for(int j=0;j<cnt;j++) a[b2[j]] = j;
		t2 = (1 << cnt);
		for(int s=0;s<t2;s++) f[s] = 0;
		for(int s=0;s<t;s++) {
			int s2 = 0;
			for(int j=0;j<p;j++)
				if( ((s >> j) & 1) && (!tag[b[j]]) )
					s2 |= (1 << a[b[j]]);
			f[s2] = max(f[s2], g[s]);
		}
		for(int j=0;j<p;j++) b[j] = 0;
		for(int j=0;j<(int)v2[i].size();j++) tag[v2[i][j]] = false;
		
		p = cnt, t = t2;
		for(int s=0;s<t;s++) g[s] = f[s];
		for(int j=0;j<(int)v1[i].size();j++)
			b2[cnt++] = v1[i][j];
		t2 = (1 << cnt);
		for(int s=0;s<t2;s++) f[s] = 0;
		for(int s=0;s<t2;s++) f[s] = g[s&(t-1)];
		p = cnt, t = t2;
		for(int j=0;j<p;j++) b[j] = b2[j];
		if( i == dcnt ) {
			printf("%d\n", f[0]);
			return 0;
		}
		else {
			for(int s=0;s<t;s++)
				if( bts[s] & 1 ) f[s] += (d[i + 1] - d[i]);
		}
	}
}