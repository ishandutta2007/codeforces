#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long lint;
typedef long double ldb;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase

const int inf = 1e9;

struct node{
    int val;
    node *l, *r;
};

node* build(int l, int r){
    node * nnode = new node;
    nnode->val = inf;
    if(l == r)
        ret nnode;
    int mid = (l + r) >> 1;
    nnode->l = build(l, mid);
    nnode->r = build(mid + 1, r);
    ret nnode;
}

int get(node * v, int l, int r, int ul, int ur){
    if(ul > ur)
        ret inf;
    if(ul == l && ur == r)
        ret v->val;
    int mid = (l + r) >> 1;
    ret min(get(v->l, l, mid, ul, min(ur, mid)), get(v->r, mid + 1, r, max(ul, mid + 1), ur));
}

void upd(node * v, int l, int r, int pos, int nv){
    if(l == r){
        v->val = min(v->val, nv);
        ret;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        upd(v->l, l, mid, pos, nv);
    else
        upd(v->r, mid + 1, r, pos, nv);
    v->val = min(v->l->val, v->r->val);
}

const int R = 1e5 + 10;

node * root;
vector<int> a, ans;
int n;
set<int> s;
map<int, int> mp;

int main(){
    scanf("%d", &n);
    a.rs(n); ans.rs(n);
    F(i, 0, n){
        scanf("%d", &a[i]);
        s.ins(a[i]);
    }
    int gt = 1;
    while(!s.empty()){
        mp[*s.begin()] = gt++;
        s.era(s.begin());
    }
    F(i, 0, n)
        a[i] = mp[a[i]];
    reverse(all(a));
    root = build(0, R);
    F(i, 0, n){
        int curr = get(root, 0, R, 0, a[i] - 1);
        if(curr == inf)
            ans[i] = -1;
        else
            ans[i] = i - 1 - curr;
        upd(root, 0, R, a[i], i);
    }
    reverse(all(ans));
    F(i, 0, n)
        printf("%d ", ans[i]);
    ret 0;
}