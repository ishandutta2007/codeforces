#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* c[26];
	int ending;
	Node() {
		for (int i=0;i<26;i++) c[i] = 0;
		ending = 0;
	}
};

void insert(Node*& cur, int on, string& word, int ind) {
	if (!cur) cur = new Node();
	if (on==word.size()) cur->ending = ind;
	else insert(cur->c[tolower(word[on])-'a'],on+1,word,ind);
}

int n,m;
char s[10013];
char buff[1013];
string words[100013];

Node* head;
int from[10013];

int main() {
	scanf("%d %s%d",&n,&s,&m);
	reverse(s,s+n);
	for (int i=1;i<=m;i++) {
		scanf(" %s",&buff);
		words[i] = string(buff);
		insert(head,0,words[i],i);
	}
	from[0] = -1;
	for (int i=0;i<n;i++) if (from[i]) {
		Node* cur = head;
		for (int j=i;j<min(i+1000,n);j++) {
			cur = cur->c[s[j]-'a'];
			if (!cur) break;
			if (cur->ending) from[j+1] = cur->ending;
		}
	}
	int loc = n;
	while (loc!=0) {
		printf("%s ",words[from[loc]].c_str());
		loc-=words[from[loc]].size();
	}
	printf("\n");

    return 0;
}