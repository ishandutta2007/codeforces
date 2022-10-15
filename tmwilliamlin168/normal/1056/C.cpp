#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, p[2000], d[2000], s[2000];
	cin >> n >> m;
	for(int i=0; i<2*n; ++i)
		cin >> p[i];
	array<int, 2> a[1000];
	memset(d, -1, sizeof(d));
	for(int i=0; i<m; ++i) {
		cin >> a[i][0] >> a[i][1], --a[i][0], --a[i][1];
		if(p[a[i][0]]<p[a[i][1]])
			swap(a[i][0], a[i][1]);
		d[a[i][0]]=a[i][1];
		d[a[i][1]]=a[i][0];
	}
	int t, ns=-1, x;
	cin >> t, --t;
	for(int it=0; it<2*n; ++it) {
		if(t) {
			cin >> x, --x;
			if(d[x]!=-1&&!s[d[x]])
				ns=d[x];
			else
				ns=-1;
			s[x]=1;
		} else {
			if(ns!=-1) {
				cout << ns+1 << endl;
				s[ns]=1;
			} else {
				bool b=0;
				for(int i=0; i<m&&!b; ++i) {
					if(!s[a[i][0]]) {
						cout << a[i][0]+1 << endl;
						s[a[i][0]]=1;
						b=1;
					}
				}
				if(!b) {
					int m1=-1;
					for(int i=0; i<2*n; ++i)
						if(!s[i]&&(m1==-1||p[m1]<p[i]))
							m1=i;
					cout << m1+1 << endl;
					s[m1]=1;
				}
			}
		}
		t^=1;
	}
}