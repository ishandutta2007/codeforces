#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *c[26], *f, *out;
	int has,vis;
	Node() {
		for (int i=0;i<26;i++) c[i] = 0;
		f = out = 0;
		has = vis = 0;
	}
};
vector<Node*> term;
void addword(string& word, int on, Node*& cur) {
	if (!cur) cur = new Node();
	if (on==word.size()) {
		cur->has+=1;
		term.push_back(cur);
	} else addword(word,on+1,cur->c[word[on]-'a']);
}
void makelinks(Node* head) {
	queue<Node*> frontier;
	head->f = head->out = head;
	for (int i=0;i<26;i++) if (head->c[i] && head->c[i]!=head) {
		head->c[i]->f = head->c[i]->out = head;
		frontier.push(head->c[i]);
	}
	while (frontier.size()>0) {
		Node* x = frontier.front();
		frontier.pop();
		for (int i=0;i<26;i++) if (x->c[i]) {
			Node* cur = x->c[i];
			Node* prev = x->f;
			while (!prev->c[i]) prev = prev->f;
			cur->f = prev->c[i];
			cur->out = (cur->f->has > cur->f->f->has) ? cur->f : cur->f->out;
			cur->has+=cur->f->has;
			frontier.push(cur);
		}
	}
}
Node* makeAC(vector<string> words) {
	Node* head = new Node();
	for (int i=0;i<words.size();i++) addword(words[i],0,head);
	for (int i=0;i<26;i++) if (!head->c[i]) head->c[i] = head;
	makelinks(head);
	return head;
}
int go(string s, Node* cur, int d=0) {
	int res = 0;
	for (char c: s) {
		while (!cur->c[c-'a']) cur = cur->f;
		cur = cur->c[c-'a'];
		res+=cur->has;
		Node* cur2 = cur;
		while (d) {
			cur2->vis+=d;
			if (cur2->f==cur2) break;
			cur2 = cur2->out;
		}
	}
	return res;
}

#define SQRT 1111

int n,Q;
char buff[100013];
string s[100013];
Node* all;
Node* head[100013];
int has[100013];

vector<int> need[100013];
int l[100013], r[100013];
long long ans[100013];

void build() {
	vector<string> curblock;
	for (int i=0;i<n;i++) curblock.push_back(s[i]);
	all = makeAC(curblock);
	curblock.clear();
	for (int i=0;i<n;i++) {
		curblock.push_back(s[i]);
		if (i%SQRT==SQRT-1) {
			head[i/SQRT] = makeAC(curblock);
			curblock.clear();
		}
	}
}

int main() {
	scanf("%d%d",&n,&Q);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		s[i] = string(buff);
	}
	build();
	for (int q=0;q<Q;q++) {
		int k;
		scanf("%d%d%d",&l[q],&r[q],&k);
		l[q]-=1; r[q]-=1; k-=1;
		need[k].push_back(q);
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n/SQRT;j++) has[j] = go(s[i],head[j]);
		go(s[i],all,1);
		for (int q: need[i]) {
			for (int b=0;b<n/SQRT;b++) {
				if (b*SQRT>=l[q] && (b+1)*SQRT-1<=r[q]) ans[q]+=has[b];
			}
			while (l[q]%SQRT!=0 && l[q]<=r[q]) {
				ans[q]+=term[l[q]]->vis;
				l[q]+=1;
			}
			while (r[q]%SQRT!=SQRT-1 && r[q]>=l[q]) {
				ans[q]+=term[r[q]]->vis;
				r[q]-=1;
			}
		}
		go(s[i],all,-1);
	}
	for (int q=0;q<Q;q++) printf("%lld\n",ans[q]);

	return 0;
}