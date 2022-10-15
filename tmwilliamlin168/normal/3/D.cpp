#include <bits/stdc++.h>
using namespace std;

int *a;
struct cmp {
	bool operator()(const int &i1, const int &i2) const {
		return a[i1]<a[i2];
	}
};

void fk() {
	cout << -1;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n=s.size(), b, o=0;
	long long t=0;
	a = new int[n];
	priority_queue<int, vector<int>, cmp> pq;
	for(int i=0; i<n; ++i) {
		if(s[i]=='?') {
			cin >> b >> a[i];
			t+=a[i];
			a[i]-=b;
			pq.push(i);
			s[i]=')';
		}
		o+=(s[i]=='(')-(s[i]==')');
		if(o<0) {
			if(pq.empty())
				fk();
			t-=a[pq.top()];
			s[pq.top()]='(';
			pq.pop();
			o+=2;
		}
	}
	if(o!=0)
		fk();
	cout << t << "\n" << s;
}