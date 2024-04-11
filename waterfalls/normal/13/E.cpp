#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
    int id,stn;
    Node *c[2], *p;
    Node(int i) { id = i, stn = 1, c[0] = c[1] = p = 0; }
};

void calc(Node* x) {
    x->stn = 1;
    for (int d=0;d<2;d++) if (x->c[d]) x->stn+=x->c[d]->stn;
}

bool isroot(Node* x) { return !x->p || (x->p->c[0]!=x && x->p->c[1]!=x); }

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
            if ((g->c[0]==p && p->c[0]==x) || (g->c[1]==p && p->c[1]==x)) rot(p);
            else rot(x);
        }
        rot(x);
    }
}

void expose(Node* x) {
    Node* p = x;
    Node* l = 0;
    while (true) {
        splay(p);
        p->c[0] = l;
        calc(p);
        l = p;
        if (!p->p) break;
        p = p->p;
    }
    splay(x);
}

void link(Node* x, Node* y) {
    expose(x);
    x->p = y;
}

void cut(Node* x) {
    expose(x);
    x->c[1]->p = 0; x->c[1] = 0;
    calc(x);
}

int path(Node* x) {
    expose(x);
    return x->stn;
}

int findroot(Node* x) {
    expose(x);
    while (x->c[1]) x = x->c[1];
    splay(x);
    return x->id;
}

Node* nodes[100013];

int N,Q;
int v[100013];

int main() {
    scanf("%d%d",&N,&Q);
    for (int i=1;i<=N;i++) {
        nodes[i] = new Node(i);
        scanf("%d",&v[i]);
    }
    for (int i=1;i<=N;i++) if (i+v[i]<=N) link(nodes[i],nodes[i+v[i]]);
    for (int q=0;q<Q;q++) {
        int type;
        scanf("%d",&type);
        if (type==0) {
            int a,b;
            scanf("%d%d",&a,&b);
            if (a+v[a]<=N) cut(nodes[a]);
            v[a] = b;
            if (a+v[a]<=N) link(nodes[a],nodes[a+v[a]]);
        } else {
            int a;
            scanf("%d",&a);
            printf("%d %d\n",findroot(nodes[a]),path(nodes[a]));
        }
    }

    return 0;
}