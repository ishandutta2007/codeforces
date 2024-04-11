#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *c[2];
    Node() {
        val = 0;
        c[0] = c[1] = 0;
    }
    Node(Node* o) {
        val = o->val;
        c[0] = o->c[0];
        c[1] = o->c[1];
    }
};

int n;

void update(Node*& x, int L, int R, int a) {
    if (!x) x = new Node();
    else x = new Node(x);
    if (L==R) x->val+=1;
    else {
        if (a<=(L+R)/2) {
            update(x->c[0],L,(L+R)/2,a);
        } else {
            update(x->c[1],(L+R)/2+1,R,a);
        }
        x->val = 0;
        for (int d=0;d<2;d++) {
            if (x->c[d]) x->val+=x->c[d]->val;
        }
    }
}

void update(Node*& x, int a) {
    update(x,0,n+1,a);
}

int querywalk(Node* x, int L, int R, int lim) {
    if (!x) return R;
    if (L==R) return R;
    int left = (x->c[0] ? x->c[0]->val : 0);
    if (left>lim) return querywalk(x->c[0],L,(L+R)/2,lim);
    return querywalk(x->c[1],(L+R)/2+1,R,lim-left);
}

Node* head[100013];

int findnext(int on, int k) {
    return querywalk(head[on],0,n+1,on-1+k);
}

int a[100013];
vector<int> push[100013];
int loc[100013];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        push[loc[a[i]]+1].push_back(i);
        loc[a[i]] = i;
    }
    head[0] = new Node();
    for (int on=1;on<=n;on++) {
        head[on] = new Node(head[on-1]);
        for (int i: push[on]) {
            update(head[on],i);
        }
    }
    for (int i=1;i<=n;i++) {
        int res = 0;
        int on = 1;
        while (on<=n) {
            on = findnext(on,i);
            res+=1;
        }
        printf("%d ",res);
    }
    printf("\n");

    return 0;
}