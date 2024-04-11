#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MP make_pair
#define A first
#define B second

struct Node {
    int val;
    Node *c[2];
    Node() { val = 0, c[0] = c[1] = 0; }
};

int st[1600013];
class ST {
private:
    int size;
    int left(int w) { return (w<<1); }
    int right(int w) { return (w<<1)+1; }
    void updateI(int w, int L, int R, int a, int b) {
        if (a<L || R<a) return;
        if (L==R) st[w] = b;
        else {
            updateI(left(w),L,(L+R)/2,a,b);
            updateI(right(w),(L+R)/2+1,R,a,b);
            st[w] = max(st[left(w)],st[right(w)]);
        }
    }
    int queryI(int w, int L, int R, int a, int b) {
        if (b<L || R<a) return 0;
        if (a<=L && R<=b) return st[w];
        return max(queryI(left(w),L,(L+R)/2,a,b),queryI(right(w),(L+R)/2+1,R,a,b));
    }
public:
    ST(int s=0) {
        size = s;
        fill(st,st+4*size,0);
    }
    void update(int a, int b) { updateI(1,0,size-1,a,b); }
    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

int n,q;
char s[400013];
int suffix[400013];
int lcp[400013];
int where[400013];
int start[400013];
int which[400013];
Node* head[400013];
int len[400013];
ST tree;
int low[400013];
int high[400013];
int who[400013];

int last[400013];
pair<pair<int,int>,int> cur[400013];
int plcp[400013];

void makeSA() {
    int N = strlen(s);
    for (int i=0;i<N;i++) where[i] = cur[i].B = i, last[i] = s[i];
    for (int k=1;k<N;k*=2) {
        for (int i=0;i<N;i++) cur[i].A = MP(last[i],cur[i].B+k<N ? last[where[cur[i].B+k]] : 0);
        sort(cur,cur+N);
        for (int i=0;i<N;i++) where[cur[i].B] = i;
        last[0] = 0;
        for (int i=1;i<N;i++) last[i] = last[i-1]+(cur[i-1].A!=cur[i].A);
    }
    for (int i=0;i<N;i++) suffix[i] = cur[i].B;
    plcp[N-1] = 0;
    for (int i=0;i<N-1;i++) {
        plcp[i] = i ? max(0,plcp[i-1]-1) : 0;
        while (s[i+plcp[i]]==s[suffix[where[i]-1]+plcp[i]]) plcp[i]+=1;
    }
    for (int i=0;i<N;i++) lcp[i] = plcp[suffix[i]];
}

void build(Node*& cur, int L, int R) {
    cur = new Node();
    if (L!=R) {
        build(cur->c[0],L,(L+R)/2);
        build(cur->c[1],(L+R)/2+1,R);
    }
}

void add(Node*& cur, Node* other, int L, int R, int a) {
    cur = new Node();
    if (L==R) cur->val = other->val+1;
    else {
        if (a<=(L+R)/2) {
            add(cur->c[0],other->c[0],L,(L+R)/2,a);
            cur->c[1] = other->c[1];
        } else {
            add(cur->c[1],other->c[1],(L+R)/2+1,R,a);
            cur->c[0] = other->c[0];
        }
        for (int d=0;d<2;d++) cur->val+=cur->c[d]->val;
    }
}

int query(Node* cur, int L, int R, int a, int b) {
    if (b<L || R<a) return 0;
    if (a<=L && R<=b) return cur->val;
    return query(cur->c[0],L,(L+R)/2,a,b)+query(cur->c[1],(L+R)/2+1,R,a,b);
}

void findlow(int pos) {
    tree = ST(pos);
    for (int i=0;i<pos;i++) {
        tree.update(lcp[i],i);
        if (who[i]) {
            low[who[i]] = tree.query(0,len[who[i]]-1);
        }
    }
}

void findhigh(int pos) {
    tree = ST(pos);
    for (int i=pos-1;i>=0;i--) {
        if (who[i]) {
            high[who[i]] = pos-tree.query(0,len[who[i]]-1)-1;
        }
        tree.update(lcp[i],pos-i);
    }
}

int main() {
    scanf("%d%d",&n,&q);
    s[0] = '$';
    int pos = 1;
    for (int i=1;i<=n;i++) {
        start[i] = pos;
        scanf(" %s",s+pos);
        while (s[pos]!='\0') pos+=1, len[i]+=1;
        s[pos++] = '$';
    }
    start[n+1] = pos;
    makeSA();
    for (int i=1;i<=n;i++) for (int j=start[i];j<start[i+1]-1;j++) which[where[j]] = i;
    for (int i=1;i<=n;i++) who[where[start[i]]] = i;
    findlow(pos);
    findhigh(pos);
    head[0] = new Node();
    build(head[0],0,n);
    for (int i=1;i<pos;i++) add(head[i],head[i-1],0,n,which[i]);
    for (int Q=0;Q<q;Q++) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        pair<int,int> range = MP(low[k],high[k]);
        printf("%d\n",query(head[range.B],0,n,l,r)-query(head[range.A-1],0,n,l,r));
    }

    return 0;
}