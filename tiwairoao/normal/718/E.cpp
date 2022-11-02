#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
int clr[MAXN + 5], n;
vector<int>v[MAXN + 5];
int d[10][MAXN + 5];
bool tag[10];
void get_dist(int x) {
	queue<int>que;
	for(int i=0;i<8;i++) tag[i] = false;
	for(int i=1;i<=n;i++) d[x][i] = MAXN + 5;
	for(int i=0;i<v[x].size();i++)
		d[x][v[x][i]] = 0, que.push(v[x][i]);
	while( !que.empty() ) {
		int f = que.front(); que.pop();
		if( !tag[clr[f]] ) {
			tag[clr[f]] = true;
			for(int i=0;i<v[clr[f]].size();i++) {
				int u = v[clr[f]][i];
				if( d[x][u] > d[x][f] + 1 )
					d[x][u] = d[x][f] + 1, que.push(u);
			}
		}
		if( f != 1 && d[x][f-1] > d[x][f] + 1 )
			d[x][f-1] = d[x][f] + 1, que.push(f-1);
		if( f != n && d[x][f+1] > d[x][f] + 1 )
			d[x][f+1] = d[x][f] + 1, que.push(f+1);
	}
}
int mnd[10][10], bts[MAXN + 5], cnt[10][1<<10];
void get_mask(int x) {
	for(int i=0;i<8;i++) {
		mnd[x][i] = MAXN + 5;
		for(int j=0;j<v[x].size();j++)
			mnd[x][i] = min(mnd[x][i], d[i][v[x][j]]);
		for(int j=0;j<v[x].size();j++)
			bts[v[x][j]] |= ((d[i][v[x][j]] - mnd[x][i])<<i);
	}
	for(int j=0;j<v[x].size();j++)
		cnt[x][bts[v[x][j]]]++;
}
int ans1; long long ans2;
void update(int x, int t) {
	if( x == ans1 ) ans2 += t;
	else if( x > ans1 ) ans1 = x, ans2 = t;
}
char s[MAXN + 5];
int abs(int x) {return x >= 0 ? x : -x;}
int main() {
	scanf("%d%s", &n, s + 1);
	for(int i=1;i<=n;i++)
		v[s[i]-'a'].push_back(i), clr[i] = s[i] - 'a';
	for(int i=0;i<8;i++) get_dist(i);
	for(int i=0;i<8;i++) get_mask(i);
	ans1 = 0, ans2 = 0;
	int t = (1<<8);
	for(int i=1;i<=n;i++) {
		for(int j=max(1,i-16);j<=min(i+16,n);j++) {
			int mn = abs(i - j);
			for(int k=0;k<8;k++)
				mn = min(mn, d[k][i] + 1 + d[k][j]);
			cnt[clr[j]][bts[j]]--, update(mn, 1);
		}
		for(int j=0;j<8;j++) {
			for(int s=0;s<t;s++) {
				int mn = MAXN + 5;
				for(int k=0;k<8;k++)
					mn = min(mn, mnd[j][k] + ((s>>k) & 1) + d[k][i] + 1);
				if( cnt[j][s] )
					update(mn, cnt[j][s]);
			}
		}
		for(int j=max(1,i-16);j<=min(i+16,n);j++)
			cnt[clr[j]][bts[j]]++;
	}
	printf("%d %lld\n", ans1, ans2/2);
}