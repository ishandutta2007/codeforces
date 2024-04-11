#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=3e5;
int n, m, a[mxN], mx[mxN], lq[mxN];
vector<int> occ[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> a[i], --a[i];
		occ[a[i]].push_back(i);
	}
	oset<ar<int, 2>> os;
	for(int i=0; i<n; ++i) {
		mx[i]=i;
		os.insert(ar<int, 2>{1, i});
		lq[i]=1;
	}
	for(int i=0; i<m; ++i) {
		//if(a[i]==0)
			//cout << (int)os.order_of_key(ar<int, 2>{lq[a[i]], a[i]}) << endl;
		mx[a[i]]=max(mx[a[i]], (int)os.order_of_key(ar<int, 2>{lq[a[i]], a[i]}));
		os.erase(ar<int, 2>{lq[a[i]], a[i]});
		os.insert(ar<int, 2>{-i, a[i]});
		lq[a[i]]=-i;
	}
	for(int i=0; i<n; ++i)
		mx[i]=max(mx[i], (int)os.order_of_key({lq[i], i}));
	for(int i=0; i<n; ++i) {
		//min
		cout << (occ[i].size()?1:i+1) << " ";
		//max
		cout << mx[i]+1 << "\n";
	}
}