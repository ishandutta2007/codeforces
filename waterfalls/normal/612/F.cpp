#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
int a[2013];
vector<int> comp;

vector<int> has[2013];
int ind[2013];
int get(int v, int i) {
	i%=(int) has[v].size();
	if (i<0) i+=has[v].size();
	return has[v][i];
}
bool cover(int v, int i, int j, bool d) {
	if (!d) swap(i,j);
	return ((ind[j]-ind[i]+has[v].size())% (int) has[v].size())==has[v].size()-1;
}

int dp[2013][2013][2];
pair<pair<int,int>,int> from[2013][2013][2];

void push(int v, int i, int j, bool d) {
	if (cover(v,i,j,d)) {
		for (int k=0;k<n;k++) if (a[k]==v-1) {
			int dist = (i-k+n)%n;
			if (dist>n-dist) dist = n-dist;
			dist+=dp[i][j][d];
			if (dist<dp[k][k][0]) {
				dp[k][k][0] = dist;
				from[k][k][0] = MP(MP(i,j),d);
			}
		}
	} else {
		int k = get(v,ind[j]+(d ? 1 : -1));
		int dist = (k-i+n)%n;
		if (dist>n-dist) dist = n-dist;
		dist+=dp[i][j][d];
		if (dist<dp[k][i][!d]) {
			dp[k][i][!d] = dist;
			from[k][i][!d] = MP(MP(i,j),d);
		}
		k = get(v,ind[i]+(d ? -1 : 1));
		dist = (k-i+n)%n;
		if (dist>n-dist) dist = n-dist;
		dist+=dp[i][j][d];
		if (dist<dp[k][j][d]) {
			dp[k][j][d] = dist;
			from[k][j][d] = MP(MP(i,j),d);
		}
	}
}

int main() {
	int s;
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	rotate(a,a+s-1,a+n);
	comp = vector<int>(a,a+n);
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	for (int i=0;i<n;i++) a[i] = lower_bound(comp.begin(),comp.end(),a[i])-comp.begin();
	int k = comp.size();
	for (int i=0;i<n;i++) {
		ind[i] = has[a[i]].size();
		has[a[i]].push_back(i);
	}
	for (int i=0;i<2013;i++) for (int j=0;j<2013;j++) for (int d=0;d<2;d++) dp[i][j][d] = 1e9;
	for (int i=0;i<n;i++) if (a[i]==k-1) {
		dp[i][i][0] = 0;
		from[i][i][0] = MP(MP(n,0),0);
	}
	for (int v=k-1;v>=0;v--) {
		for (int l=0;l<has[v].size();l++) {
			for (int i=0;i<n;i++) if (a[i]==v) {
				int j = get(v,ind[i]+l);
				push(v,i,j,1);
				j = get(v,ind[i]-l);
				push(v,i,j,0);
			}
		}
	}
	int best = 1e9;
	auto where = MP(MP(0,0),0);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int d=0;d<2;d++) {
		if (a[i]==0 && a[j]==0 && cover(0,i,j,d)) {
			if (dp[i][j][d]+min(i,n-i)<best) {
				best = dp[i][j][d]+min(i,n-i);
				where = MP(MP(i,j),d);
			}
		}
	}
	from[0][n][0] = where;
	where = MP(MP(0,n),0);
	printf("%d\n",best);
	while (true) {
		int prev = where.A.A;
		where = from[where.A.A][where.A.B][where.B];
		if (where.A.A==n) break;
		char c = '+';
		int dist = (where.A.A-prev+n)%n;
		if (dist>n-dist) {
			c = '-';
			dist = n-dist;
		}
		printf("%c%d\n",c,dist);
	}

	return 0;
}