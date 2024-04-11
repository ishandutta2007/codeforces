#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, k, d1[101], d2[101], m, r[101], c[101], g[4][50];

struct move {
	int i, r, c;
} ms[20000];

inline void am(int i) {
	ms[m++]={i, r[i], c[i]};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<4; ++i) {
		for(int j=0; j<n; ++j) {
			cin >> g[i][j];
			if(!g[i][j])
				continue;
			if(i==0||i==3) {
				if(i==3)
					d1[g[i][j]]=1;
				d2[g[i][j]]=j;
			} else {
				r[g[i][j]]=i;
				c[g[i][j]]=j;
			}
		}
	}
	bool ch=1;
	while(ch) {
		ch=0;
		for(int i=1; i<=k; ++i) {
			if(r[i]==0||r[i]==3)
				continue;
			if(r[i]-1==d1[i]&&c[i]==d2[i]) {
				g[r[i]][c[i]]=0;
				if(d1[i]==0)
					--r[i];
				else
					++r[i];
				am(i);
				ch=1;
				continue;
			}
			int nr=r[i], nc=c[i];
			if(r[i]==1) {
				if(c[i]==0)
					nr=2;
				else
					nc=c[i]-1;
			} else {
				if(c[i]==n-1)
					nr=1;
				else
					nc=c[i]+1;
			}
			if(g[nr][nc])
				continue;
			ch=1;
			g[r[i]][c[i]]=0;
			g[nr][nc]=i;
			r[i]=nr;
			c[i]=nc;
			am(i);
		}
	}
	for(int i=1; i<=k; ++i) {
		if(r[i]==1||r[i]==2) {
			cout << -1;
			return 0;
		}
	}
	cout << m << "\n";
	for(int i=0; i<m; ++i)
		cout << ms[i].i << " " << ms[i].r+1 << " " << ms[i].c+1 << "\n";
}