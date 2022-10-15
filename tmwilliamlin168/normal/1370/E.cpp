#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s, t;
	cin >> n >> s >> t;
	int a0=0, a1=0;
	for(char c : s) {
		if(c&1)
			++a1;
		else
			++a0;
	}
	for(char c : t) {
		if(c&1)
			--a1;
		else
			--a0;
	}
	if(a0||a1) {
		cout << -1;
		return 0;
	}
	vector<int> v;
	vector<int> w;
	int ans=0;
	for(int i=0; i<n; ++i)
		if(s[i]^t[i]) {
			if(v.empty()||v.back()!=(s[i]&1))
				w.push_back(0);
			v.push_back(s[i]&1);
			++w.back();
			//ans=max(ans, w.back());
		}
	//if(w.size()&1&&w.size()>1)
		//ans=max(ans, w[0]+w.back());
	while(w.size()) {
		if(w.size()&1) {
			w[0]+=w.back();
			w.pop_back();
		}
		for(int i=0; i<w.size(); i+=2) {
			--w[i];
			--w[i+1];
		}
		++ans;
		int j=0;
		while(j<w.size()&&!w[j])
			++j;
		if(j>=w.size())
			break;
		vector<int> w2={w[j]};
		int l=j&1;
		for(int i=j+1; i<w.size(); ++i) {
			if(w[i]) {
				if((i&1)^l) {
					w2.push_back(0);
				}
				w2.back()+=w[i];
				l=i&1;
			}
		}
		w=w2;
	}
	cout << ans;
}