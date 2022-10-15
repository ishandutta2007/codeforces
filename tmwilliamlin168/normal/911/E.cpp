#include <bits/stdc++.h>
using namespace std;

inline void fk() {
	cout << -1;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, c=1;
	cin >> n >> k;
	int *a = new int[n];
	stack<int> s;
	s.push(n+1);
	for(int i=0; i<k; ++i) {
		cin >> a[i];
		if(a[i]>s.top())
			fk();
		s.push(a[i]);
		while(!s.empty()&&s.top()==c) {
			s.pop();
			++c;
		}
	}
	for(int i=k; i<n; ++i) {
		a[i]=s.top()-1;
		s.push(a[i]);
		while(!s.empty()&&s.top()==c) {
			s.pop();
			++c;
		}
	}
	for(int i=0; i<n; ++i)
		cout << a[i] << " ";
}