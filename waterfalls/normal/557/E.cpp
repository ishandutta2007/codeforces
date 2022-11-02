#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct Node {
    int val,sts;
    Node *c[2];
    Node() { val = sts = 0, c[0] = c[1] = 0; }
};

int n;
char s[5013];
bool ok[5013][5013];
vector<char> ans;

Node* insert(Node* cur, int start, int pos) {
    if (!cur) cur = new Node();
    if (pos>start && ok[start][pos-1]) cur->val+=1;
    if (pos==n) return cur;
    if (s[pos]=='a') cur->c[0] = insert(cur->c[0],start,pos+1);
    else cur->c[1] = insert(cur->c[1],start,pos+1);
    return cur;
}

void make(Node* x) {
    x->sts = x->val;
    for (int d=0;d<2;d++) if (x->c[d]) make(x->c[d]), x->sts+=x->c[d]->sts;
}

void dfs(Node* x, int k) {
    if (x->val>=k) return;
    k-=x->val;
    int l = x->c[0] ? x->c[0]->sts : 0;
    if (l>=k) {
        ans.push_back('a');
        dfs(x->c[0],k);
    } else {
        ans.push_back('b');
        dfs(x->c[1],k-l);
    }
}

int k;
Node* head;

int main() {
    scanf(" %s%d",&s,&k);
    n = strlen(s);
    for (int i=0;i<n;i++) ok[i][i] = 1;
    for (int i=0;i<n-1;i++) if (s[i]==s[i+1]) ok[i][i+1] = 1;
    for (int i=0;i<n-2;i++) if (s[i]==s[i+2]) ok[i][i+2] = 1;
    for (int i=0;i<n-3;i++) if (s[i]==s[i+3]) ok[i][i+3] = 1;
    for (int l=4;l<n;l++) {
        for (int i=0;i+l<n;i++) {
            int j = i+l;
            if (ok[i+2][j-2] && s[i]==s[j]) ok[i][j] = 1;
        }
    }
    for (int i=0;i<n;i++) head = insert(head,i,i);
    make(head);
    dfs(head,k);
    for (int i=0;i<ans.size();i++) printf("%c",ans[i]);
    printf("\n");

    return 0;
}