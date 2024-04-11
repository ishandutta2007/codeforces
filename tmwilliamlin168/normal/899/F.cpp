#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

inline int d1(char c) {
	if(c<='9')
		return c-'0';
	if(c<='Z')
		return c-'A'+10;
	return c-'a'+36;
}
inline char d2(int x) {
	if(x<10)
		return x+'0';
	if(x<36)
		return x-10+'A';
	return x-36+'a';
}

int a[200000];
ordered_set<int> remain1, remain2[62];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	string s;
	cin >> n >> m >> s;
	for(int i=0; i<n; ++i) {
		a[i]=d1(s[i]);
		remain1.insert(i);
		remain2[a[i]].insert(i);
	}
	for(int i=0; i<m; ++i) {
		int l1, r1;
		char c;
		cin >> l1 >> r1 >> c;
		int l2=*remain1.find_by_order(l1-1), r2=*remain1.find_by_order(r1-1), x=d1(c);
		auto it=remain2[x].lower_bound(l2);
		while(it!=remain2[x].end()&&*it<=r2) {
			remain1.erase(*it);
			it=remain2[x].erase(it);
		}
	}
	for(int i : remain1)
		cout << d2(a[i]);
}