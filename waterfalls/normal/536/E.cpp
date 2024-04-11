#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int f[100013];

struct Node {
    int sts,val,stn,s[2],id;
    Node *c[2], *p;
    Node(int i=0) { id = i, sts = val = s[0] = s[1] = 0, stn = 1, c[0] = c[1] = p = 0; }
    Node(int l, int r, int ss, int n) { sts = ss, s[0] = l, s[1] = r; stn = n; }
    Node(Node* l, Node* r, int v) { val = v, c[0] = l, c[1] = r; }
};

bool isroot(Node* x) { return !x->p || (x->p->c[1]!=x && x->p->c[0]!=x); }

void calc(Node* x) {
    x->sts = 0, x->stn = 1;
    if (x->val==-1) x->stn = 0;
    for (int d=0;d<2;d++) if (x->c[d]) x->sts+=x->c[d]->sts, x->stn+=x->c[d]->stn;
    if (x->val==-1) {
        int ok = 1;
        for (int d=0;d<2;d++) if (!x->c[d] || x->c[d]->s[!d]==x->c[d]->stn) ok = 0;
        if (ok) {
            ok = 0;
            for (int d=0;d<2;d++) ok+=x->c[d]->s[!d];
            x->sts+=f[ok];
        }
        x->s[0] = x->s[1] = 0;
        for (int d=0;d<2;d++) {
            if (x->c[d]) {
                x->s[d] = x->c[d]->s[d];
                if (x->c[!d] && x->c[d]->s[d]==x->c[d]->stn) x->s[d] = x->c[d]->stn+x->c[!d]->s[d];
                if (!x->c[!d]) x->s[!d] = x->c[d]->s[!d];
            }
        }
    } else {
        if (x->val==0) {
            for (int d=0;d<2;d++) if (x->c[d]) {
                if (x->c[d]->s[!d]!=x->c[d]->stn) x->sts+=f[x->c[d]->s[!d]];
            }
            for (int d=0;d<2;d++) x->s[d] = x->c[d] ? x->c[d]->s[d] : 0;
        } else {
            int ok = 1;
            for (int d=0;d<2;d++) if (!x->c[d] || x->c[d]->s[!d]==x->c[d]->stn) ok = 0;
            if (ok) {
                for (int d=0;d<2;d++) ok+=x->c[d]->s[!d];
                x->sts+=f[ok];
            }
            x->s[0] = x->s[1] = 1;
            for (int d=0;d<2;d++) {
                if (x->c[d]) {
                    x->s[d] = (x->c[d]->s[d]==x->c[d]->stn) ? x->c[d]->stn+1 : x->c[d]->s[d];
                    if (x->c[!d] && x->c[d]->s[d]==x->c[d]->stn) x->s[d] = x->c[d]->stn+1+x->c[!d]->s[d];
                    if (!x->c[!d]) x->s[!d] = 1+x->c[d]->s[!d];
                }
            }
        }
    }
}

void rot(Node* x) {
    Node* p = x->p;
    if (isroot(p)) x->p = p->p;
    else {
        int d = p->p->c[1]==p;
        p->p->c[d] = x; x->p = p->p;
    }
    int d = p->c[1]==x;
    p->c[d] = x->c[!d]; if (x->c[!d]) x->c[!d]->p = p;
    x->c[!d] = p; p->p = x;
    calc(p); calc(x);
}

void splay(Node* x) {
    while (!isroot(x)) {
        Node* p = x->p;
        if (!isroot(p)) {
            Node* g = p->p;
            if ((g->c[1]==p)==(p->c[1]==x)) rot(p);
            else rot(x);
        }
        rot(x);
    }
}

Node* expose(Node* x) {
    Node* p = x;
    Node* l = 0;
    while (true) {
        splay(p);
        p->c[0] = l;
        calc(p);
        l = p;
        if (p->p) p = p->p;
        else break;
    }
    splay(x);
    return p;
}

void link(Node* x, Node* p) {
    expose(x);
    x->p = p;
}

void cut(Node* x) {
    expose(x);
    if (x->c[1]) x->c[1]->p = 0;
    x->c[1] = 0;
    calc(x);
}

int lca(Node* x, Node* y) {
    expose(x);
    return expose(y)->id;
}

Node* path(Node* x) {
    expose(x);
    return new Node(x->s[0],x->s[1],x->sts,x->stn);
}

void give(Node* x, int v) {
    expose(x);
    x->val = v;
    calc(x);
}

#define MP make_pair
#define A first
#define B second

int n,q;
vector<pair<int,int> > adj[100013];
vector<int> comp;
vector<int> has[100013];
vector<pair<pair<int,int>,int> > queries[100013];
int p[100013];
Node* nodes[100013];
int ans[100013];

void dfs(int x, int pp=0) {
    p[x] = pp;
    if (pp) link(nodes[x],nodes[pp]);
    for (pair<int,int> i: adj[x]) {
        if (i.A==pp) has[i.B].push_back(x);
        else dfs(i.A,x);
    }
}

int query(int a, int b) {
    int l = lca(nodes[a],nodes[b]);
    if (l!=1) cut(nodes[l]);
    int v = nodes[l]->val;
    give(nodes[l],-1);
    Node* one = path(nodes[a]);
    Node* two = path(nodes[b]);
    give(nodes[l],v);
    swap(two->s[0],two->s[1]);
    Node* top = new Node(one,two,-1);
    calc(top);
    int res = top->sts+f[top->s[0]]+f[top->s[1]];
    if (top->s[0]==top->stn) res = f[top->stn];
    if (l!=1) link(nodes[l],nodes[p[l]]);
    return res;
}

int main() {
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n-1;i++) scanf("%d",&f[i]);
    for (int i=0;i<n-1;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        comp.push_back(w);
        adj[u].push_back(MP(v,w));
        adj[v].push_back(MP(u,w));
    }
    comp.push_back(0);
    comp.push_back(1e9+7);
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    for (int i=1;i<=n;i++) {
        for (pair<int,int>& j: adj[i]) j.B = lower_bound(comp.begin(),comp.end(),j.B)-comp.begin();
    }
    for (int i=1;i<=n;i++) nodes[i] = new Node(i);
    give(nodes[1],-1);
    dfs(1);
    for (int i=0;i<q;i++) {
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        l = lower_bound(comp.begin(),comp.end(),l)-comp.begin();
        queries[l].push_back(MP(MP(u,v),i));
    }
    for (int i=comp.size()-1;i>=0;i--) {
        for (int j: has[i]) give(nodes[j],1);
        for (pair<pair<int,int>,int> Q: queries[i]) {
            ans[Q.B] = query(Q.A.A,Q.A.B);
        }
    }
    for (int i=0;i<q;i++) printf("%d\n",ans[i]);

    return 0;
}