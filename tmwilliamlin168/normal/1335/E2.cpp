#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, a[mxN], ans;
vector<int> occ[200], v;

void solve() {
	int l=0, r=(int)v.size()-1, x=0, s=0;
	for(int a : v)
		s+=a;
	ans=max(s, ans);
	while(1) {
		++x;
		bool bl=0, br=0;
		while(l<=r&&!bl) {
			if(!v[l])
				bl=1;
			else
				--s;
			++l;
		}
		while(l<=r&&!br) {
			if(!v[r])
				br=1;
			else
				--s;
			--r;
		}
		/*
		if(v.size()>=6) {
			for(int vi : v)
				cout << vi << " ";
			cout << endl;
			cout << x << " " << s << endl;
		}
		*/
		if(!bl||!br)
			break;
		//if(v.size()>=3)
		//cout << x << " " << s << endl;
		ans=max(2*x+s, ans);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; ++i) {
			cin >> a[i], --a[i];
			occ[a[i]].push_back(i);
		}
		for(int i=0; i<200; ++i)
			occ[i].push_back(n);
		ans=0;
		for(int a=0; a<200; ++a) {
			if(occ[a].size()==1)
				continue;
			for(int b=0; b<200; ++b) {
				if(a==b) {
					ans=max((int)occ[a].size()-1, ans);
					continue;
				}
				for(int i=0, j=0; i<occ[a].size()-1||j<occ[b].size()-1; ) {
					if(occ[a][i]<occ[b][j]) {
						v.push_back(0);
						++i;
					} else {
						v.push_back(1);
						++j;
					}
				}
				solve();
				v.clear();
			}
		}
		cout << ans << "\n";
		for(int i=0; i<200; ++i)
			occ[i].clear();
	}
}