#include <bits/stdc++.h>
using namespace std;

class FTree {
public:
	int *a, n;
	FTree(int n) {
		this->n=n;
		a = new int[n+1]();
	}
	void upd(int i, int x) {
		for(++i; i<=n; i+=i&-i)
			a[i]+=x;
	}
	int sum(int n) {
		int t=0;
		for(; n>0; n-=n&-n)
			t+=a[n];
		return t;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int *a = new int[n];
	set<int> s[100001];
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		s[a[i]].insert(i);
	}
	FTree ftree(n);
	long long t=0;
	int li=-1;
	for(int k=1; k<=100000; ++k) {
		while(!s[k].empty()) {
			auto it=s[k].upper_bound(li);
			bool wrap=it==s[k].end();
			if(wrap) {
				t+=(n-1-li)-(ftree.sum(n)-ftree.sum(li+1));
				it=s[k].lower_bound(0);
				li=-1;
			}
			t+=(*it-li)-(ftree.sum(*it+1)-ftree.sum(li+1));
			ftree.upd(*it, 1);
			li=*it;
			s[k].erase(it);
		}
	}
	cout << t;
}