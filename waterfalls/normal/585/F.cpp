#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *c[10], *f;
	bool has;
	int ind;
	Node(int id) {
		for (int i=0;i<10;i++) c[i] = 0;
		f = 0;
		has = 0;
		ind = id;
	}
};

vector<Node*> nodes;
Node* make() {
	nodes.push_back(new Node(nodes.size()));
	return nodes.back();
}

void addword(Node*& cur, int on, string& t) {
	if (!cur) cur = make();
	if (on==t.size()) cur->has = 1;
	else addword(cur->c[t[on]-'0'],on+1,t);
}
void makelinks(Node* head) {
	for (int i=0;i<10;i++) if (!head->c[i]) head->c[i] = head;
	queue<Node*> frontier;
	for (int i=0;i<10;i++) if (head->c[i]!=head) {
		head->c[i]->f = head;
		frontier.push(head->c[i]);
	}
	while (frontier.size()) {
		Node* r = frontier.front();
		frontier.pop();
		for (int i=0;i<10;i++) if (r->c[i]) {
			Node* x = r->c[i];
			Node* y = r->f;
			while (!y->c[i]) y = y->f;
			x->f = y->c[i];
			x->has|=x->f->has;
			frontier.push(x);
		}
	}
}
void makeAC(string s, int d) {
	Node* head = make();
	for (int i=0;i<s.size();i++) {
		if (i+d<=s.size()) {
			string t = s.substr(i,d);
			addword(head,0,t);
		}
	}
	makelinks(head);
}

typedef long long ll;
const int MOD = 1e9+7;
int add(int a, int b) { return (a+b)%MOD; }
int sub(int a, int b) { return (a-b+MOD)%MOD; }
int mult(int a, int b) { return ((ll) a*b)%MOD; }

int get(string s) {
	int dp[s.size()+1][nodes.size()][2][2]; // place in s, AC node on, has occ, already below
	memset(dp,0,sizeof dp);
	dp[0][0][0][0] = 1;
	for (int i=0;i<s.size();i++) for (int j=0;j<nodes.size();j++) {
		for (int a=0;a<2;a++) for (int b=0;b<2;b++) {
			if (dp[i][j][a][b]) {
				for (int d=0;d<10;d++) {
					if (!b && '0'+d>s[i]) continue;
					Node* cur = nodes[j];
					while (!cur->c[d]) cur = cur->f;
					int nj = cur->c[d]->ind;
					int na = a|cur->c[d]->has;
					int nb = b|('0'+d<s[i]);
					dp[i+1][nj][na][nb] = add(dp[i+1][nj][na][nb],dp[i][j][a][b]);
				}
			}
		}
	}
	int ans = 0;
	for (int j=0;j<nodes.size();j++) for (int b=0;b<2;b++) ans = add(ans,dp[s.size()][j][1][b]);
	return ans;
}

int main() {
	string s,A,B;
	cin >> s >> A >> B;
	makeAC(s,A.size()/2);
	int on = A.size()-1;
	while (A[on]=='0') on-=1;
	A[on]-=1;
	while (++on<A.size()) A[on] = '9';
	cout << sub(get(B),get(A)) << endl;

	return 0;
}