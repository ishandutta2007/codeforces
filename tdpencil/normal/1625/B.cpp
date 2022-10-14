#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ar array
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
struct treap {
	struct node {
		int prior = uniform_int_distribution<int>(1,1000000000)(rng);
		T num;
		node *left, *right;
		node(T x) :  num(x) {}
		node() : num(0) {}
	};
	
	node *root;
	void add(node *root, node *added) {
		if(!root) root=added;
		else if(root->prior>added.prior) {
			if(root->left==nullptr) {
				root->left = added;
			} else {
				add(root->left,added);
			}
		} else if(root->prior<added.prior) {
			if(root->right==nullptr) {
				root->right = added;
			} else {
				add(root->right,added);
			}
		}
	}
	void add(T x) {
		node *newNode = new node(x);
		add(root, newNode);
	}

	void print(node *root) {
		if(!root)
			return;
		cout << (root->num) << " ";
		print(root->left);
		print(root->right);
	}
};

int main() {
	
	ios::sync_with_stdio(false); cin.tie(0);

	int te; cin >> te;
	vector<vector<int>> loc(150001);	
	while(te--) {
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i], loc[a[i]].push_back(i);
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()), a.end());
		int ans=-1;
		for(int i = 0; i < (int) a.size(); i++) {
			for(int j = 1; j < (int)loc[a[i]].size();j++) {
				ans = max(ans,loc[a[i]][j-1]-loc[a[i]][j]+n);
			}
			loc[a[i]].clear();
		}

		cout << ans << "\n";
	}
	
}