#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct Node {
    int link[2] = {-1, -1};
	int val=0;
};

class Trie {
public:
    Trie(int _lvlMax) {
        nodes.push_back(Node());
        lvlMax = _lvlMax;
    }

    void add(int value) {
        int node = 0;
		nodes[0].val++;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1) {
                int x = newNode();
                nodes[node].link[b] = x;
            }
            node = nodes[node].link[b];
			nodes[node].val++;
        }
    }

    int getMin(int value) {
        int node = 0;
        int ans = 0;
        for (int lvl = lvlMax; lvl >= 0; --lvl) {
            int b = !!(value & (1 << lvl));
            if (nodes[node].link[b] == -1||nodes[nodes[node].link[b]].val==0) {
				ans |= 1 << lvl;
                node = nodes[node].link[b ^ 1];
				nodes[node].val--;
            } else {
                node = nodes[node].link[b];
				nodes[node].val--;
            }
        }
        return ans;
    }
private:
    vector<Node> nodes;
    int lvlMax;
    int newNode() {
        nodes.push_back(Node());
        return sz(nodes) - 1;
    }
};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	Trie t(30);
	int n;cin>>n;
	int a[n];
	rep(i,n) cin>>a[i];
	rep(i,n){
		int x;cin>>x;
		t.add(x);
	}
	rep(i,n){
		int x=a[i];
		cout<<t.getMin(x)<<' ';
	}
	return 0;
}