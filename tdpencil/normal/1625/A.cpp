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
		if(root->prior>added.prior) {
			if(root->left==nullptr) {
				root->left = added;
			} else {
				add(root->left,added);
			}
		} else if(root->prior<added.prior) {
			if(root->right==nullptr) {
				
			}
		}
	}
	void add(T x) {
		node *newNode = new node(x);
		add(root, newNode);
	}
};

int main() {
	
	ios::sync_with_stdio(false); cin.tie(0);

	int te; cin >> te;
	
	while(te--) {
		int n, l;
		cin >> n >> l;
		
		vector<int> cnt(l);
		
		for(int i = 0, x; i < n; i++) {
			cin >> x;
			for(int j = 0; j < l; j++) {
				if((1<<j)&x) cnt[j]++;
			}
		}
		
		int ans=0;
		for(int j=0;j<l;j++) {
			if(cnt[j]*2>=n) ans+=1<<j;
		}
		cout << ans << "\n";
	}
	
}