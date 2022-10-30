#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;

struct Node {
    int sts,val,id;
    Node *c[2], *p;
    Node(int i=0) { id = i, sts = val = 0, c[0] = c[1] = p = 0; }
};

bool isroot(Node* x) { return !x->p || (x->p->c[0]!=x && x->p->c[1]!=x); }

void calc(Node* x) {
    x->sts = x->val;
    for (int d=0;d<2;d++) if (x->c[d]) x->sts = min(x->sts,x->c[d]->sts);
}

void rot(Node* x) {
    Node* p = x->p;
    if (!isroot(p)) {
        Node* g = p->p;
        int d = (g->c[1]==p);
        g->c[d] = x; x->p = p->p;
    } else x->p = p->p;
    int d = (p->c[1]==x);
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

int path(Node* x) {
    expose(x);
    return x->sts;
}

void give(Node* x, int v) {
    expose(x);
    x->val = v;
    calc(x);
}

Node* nodes[200013];

pair<int,int> MP(int a, int b) { return make_pair(min(a,b),max(a,b)); }
#define A first
#define B second

int n,m,q,counter,on;
int w[200013];
set<int> adj[200013];
set<int> adj2[200013];
int num[200013];
int low[200013];
int art[200013];
int art2[200013];
int id[200013];
multiset<int> has[200013];
int pa[200013];

void findart(int x, int p=0) {
    low[x] = num[x] = counter++;
    int child = 0;
    for (int i: adj[x]) {
        if (!num[i]) {
            findart(i,x);
            low[x] = min(low[x],low[i]);
            child+=1;
            if (!art[x] && ((x==1 && child>1) || (x!=1 && low[i]>=num[x]))) {
                art[x] = 1;
                art2[on] = x;
                id[x] = on++;
            }
        } else if (i!=p) low[x] = min(low[x],num[i]);
    }
}

void put(int x) {
    if (!art[x]) {
        if (!id[x]) has[on].insert(w[x]);
        id[x] = on;
    } else {
        adj2[id[x]].insert(on);
        adj2[on].insert(id[x]);
    }
}

stack<pair<int,int> > s;
void dfs(int x, int p=0) {
    low[x] = num[x] = counter++;
    for (int i: adj[x]) {
        if (!num[i]) {
            s.push(MP(x,i));
            dfs(i,x);
            low[x] = min(low[x],low[i]);
            if (low[i]>=num[x]) {
                while (true) {
                    put(s.top().A);
                    put(s.top().B);
                    if (s.top()==MP(x,i)) break;
                    s.pop();
                }
                s.pop();
                on+=1;
            }
        } else if (i!=p && num[i]<num[x]) {
            low[x] = min(low[x],num[i]);
            s.push(MP(x,i));
        }
    }
}

void make(int x, int p=0) {
    pa[x] = p;
    if (x!=p) link(nodes[x],nodes[p]);
    for (int i: adj[x]) if (i!=p) {
        make(i,x);
        if (!art[x]) has[x].insert(w[art[i]]);
    }
    if (art[x]) give(nodes[x],w[art[x]]);
    else give(nodes[x],*has[x].begin());
}

void update(int x, int v) {
    int which = id[x];
    if (art[which]) {
        if (which!=1) {
            int above = pa[which];
            has[above].erase(has[above].find(w[x]));
        }
        w[x] = v;
        give(nodes[which],w[x]);
        if (which!=1) {
            int above = pa[which];
            has[above].insert(w[x]);
            give(nodes[above],*has[above].begin());
        }
    } else {
        has[which].erase(has[which].find(w[x]));
        w[x] = v;
        has[which].insert(w[x]);
        give(nodes[which],*has[which].begin());
    }
}

int query(int a, int b) {
    if (a==b) return w[a];
    a = id[a]; b = id[b];
    int l = lca(nodes[a],nodes[b]);
    int ans = 2147483647;
    if (l!=1 && !art[l]) ans = min(ans,nodes[pa[l]]->val);
    if (l!=1) cut(nodes[l]);
    ans = min(ans,path(nodes[a]));
    ans = min(ans,path(nodes[b]));
    if (l!=1) link(nodes[l],nodes[pa[l]]);
    return ans;
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    on = 1;
    findart(1);
    for (int i=1;i<=n;i++) num[i] = low[i] = 0;
    counter = 1;
    dfs(1);
    swap(adj,adj2);
    swap(art,art2);
    for (int i=1;i<on;i++) nodes[i] = new Node(i);
    make(1);
    for (int Q=0;Q<q;Q++) {
        char c;
        int a,b;
        scanf(" %c%d%d",&c,&a,&b);
        if (c=='C') update(a,b);
        else printf("%d\n",query(a,b));
    }

    return 0;
}