#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define A first
#define B second

struct Node {
    vector<int> a;
    vector<int> b;
    Node* c[26];
    Node() {
        for (int i=0;i<26;i++) c[i] = 0;
    }
};

void insert(Node* x, string& s, int w, int ind, bool l) {
    if (w==s.size()) {
        if (l==0) x->a.push_back(ind);
        else x->b.push_back(ind);
    } else {
        if (!x->c[s[w]-'a']) x->c[s[w]-'a'] = new Node();
        insert(x->c[s[w]-'a'],s,w+1,ind,l);
    }
}

int n;
Node* head;
int match[100013];

int ans;
pair<vector<int>,vector<int> > dfs(Node* x, int d) {
    pair<vector<int>,vector<int> > res;
    for (int j: x->a) res.A.push_back(j);
    for (int j: x->b) res.B.push_back(j);
    for (int i=0;i<26;i++) if (x->c[i]) {
        auto a = dfs(x->c[i],d+1);
        for (int j: a.A) res.A.push_back(j);
        for (int j: a.B) res.B.push_back(j);
    }
    while (res.A.size() && res.B.size()) {
        match[res.A.back()] = res.B.back();
        res.A.pop_back();
        res.B.pop_back();
        ans+=d;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    head = new Node();
    cin >> n;
    for (int i=0;i<2*n;i++) {
        string s;
        cin >> s;
        insert(head,s,0,i%n+1,i>=n);
    }
    ans = 0;
    dfs(head,0);
    cout << ans << '\n';
    for (int i=1;i<=n;i++) cout << i << " " << match[i] << '\n';

    return 0;
}