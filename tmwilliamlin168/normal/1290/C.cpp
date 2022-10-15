#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, k, p[mxN], c[mxN];
string s;
vector<int> v[mxN];
bool t[mxN], d[mxN];

ar<int, 2> find(int x) {
	if(x^p[x]) {
		ar<int, 2> a=find(p[x]);
		p[x]=a[0];
		t[x]^=a[1];
		return {a[0], t[x]};
	}
	return {x, 0};
}

void join(int x, int y) {
	p[y]=x;
	c[x]+=c[y];
	t[y]^=t[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	cin >> s;
	for(int i=0; i<k; ++i) {
		int l;
		cin >> l;
		for(int j=0, a; j<l; ++j) {
			cin >> a, --a;
			v[a].push_back(i);
		}
		c[i]=1;
	}
	iota(p, p+k, 0);
	for(int i=0, ans=0; i<n; ++i) {
		//cout << i << endl;
		bool b=s[i]&1;
		for(int &j : v[i]) {
			ar<int, 2> a=find(j);
			j=a[0];
			b^=a[1]^t[j];
		}
		for(int j=(int)v[i].size()-1; ~j; --j)
			if(d[v[i][j]])
				v[i].erase(v[i].begin()+j);
		if(v[i].size()==2&&v[i][0]==v[i][1])
			v[i].clear();
		if(!b) {
			//v[i].size() should be positive
			if(v[i].size()==1) {
				ans+=c[v[i][0]];
				t[v[i][0]]^=1;
				c[v[i][0]]=-c[v[i][0]];
				d[v[i][0]]=1;
			} else if(v[i].size()==2) {
				if(c[v[i][0]]>c[v[i][1]])
					swap(v[i][0], v[i][1]);
				ans+=c[v[i][0]];
				t[v[i][0]]^=1;
				c[v[i][0]]=-c[v[i][0]];
				join(v[i][0], v[i][1]);
			} else {
				assert(0);
			}
		} else {
			if(v[i].size()==1) {
				d[v[i][0]]=1;
			} else if(v[i].size()==2) {
				join(v[i][0], v[i][1]);
			}
		}
		//cout << i << endl;
		//for(int j=0; j<k; ++j)
			//cout << j << " " << find(j)[1] << endl;
		cout << ans << "\n";
	}
}