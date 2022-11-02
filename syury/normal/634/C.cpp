#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cassert>
#include<ctime>

#define X first
#define Y second

using namespace std;

typedef long long int lint;
typedef long double ldb;

struct node{
    node *l, *r;
    lint val;
};

node * build(int l, int r){
    node * nnode = new node;
    if(l == r){
        nnode->l = nnode->r = NULL;
        nnode->val = 0;
    }
    else{
        int mid = (l + r) >> 1;
        nnode->l = build(l, mid);
        nnode->r = build(mid + 1, r);
        nnode->val = 0;
    }
    return nnode;
}

lint get(node * v, int l, int r, int ul, int ur){
    if(ul > ur)
        return 0ll;
    if(l == ul && r == ur)
        return v->val;
    int mid = (l + r) >> 1;
    lint res = get(v->l, l, mid, ul, min(ur, mid)) + get(v->r, mid + 1, r, max(mid + 1, ul), ur);
    return res;
}

void upd(node * v, int l, int r, int pos, int add, int maxv){
    if(l == r){
        v->val += add;
        v->val = min((lint)maxv, v->val);
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        upd(v->l, l, mid, pos, add, maxv);
    else
        upd(v->r, mid + 1, r, pos, add, maxv);
    v->val = v->l->val + v->r->val;
}

int n, k, a, b, q;
vector<lint> val, ss, ps;
node * ra, * rb;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    ra = build(0, n + 1);
    rb = build(0, n + 1);
    for(int i = 0; i < q; i++){
        int type;
        scanf("%d", &type);
        if(type == 1){
            int add, id;
            scanf("%d%d", &id, &add);
            id--;
            upd(ra, 0, n + 1, id, add, a);
            upd(rb, 0, n + 1, id, add, b);
        }
        else{
            int p;
            scanf("%d", &p);
            p--;
            int rp = p + k - 1;
            lint curr = get(rb, 0, n + 1, 0, p - 1) + get(ra, 0, n + 1, rp + 1, n + 1);
            printf("%I64d\n", curr);
        }
    }
    return 0;
}