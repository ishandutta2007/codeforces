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

const int inf = 1e9;

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

struct node{
    node *l, *r;
    int val;
};

node * build(int l, int r){
    node * v = new node;
    v->val = inf;
    if(l == r)
        ret v;
    int m = (l + r) >> 1;
    v->l = build(l, m);
    v->r = build(m + 1, r);
    ret v;
}

void upd(node *v, int l, int r, int pos, int nv){
    if(l == r){v->val = nv; ret;}
    int mid = (l + r) >> 1;
    if(pos <= mid)
        upd(v->l, l, mid, pos, nv);
    else
        upd(v->r, mid + 1, r, pos, nv);
    v->val = min(v->l->val, v->r->val);
}

int get(node * v, int l, int r, int ul, int ur){
    if(ul > ur)
        ret inf;
    if(l == ul && r == ur)
        ret v->val;
    int mid = (l + r) >> 1;
    ret min(get(v->l, l, mid, ul, min(ur, mid)), get(v->r, mid + 1, r, max(ul, mid + 1), ur));
}

node * root;
int n, s, ms;
vector<int> a;
vector<vector<int> > st[2];

int stget(int g, int l, int r){
    int sz = r - l + 1;
    int len = 1;
    int p = 0;
    while(len <= sz){len *= 2; p++;}
    len /= 2; p--;
    if(g == 0)
        ret min(st[g][l][p], st[g][r - len + 1][p]);
    else
        ret max(st[g][l][p], st[g][r - len + 1][p]);
}

int main(){
    scanf("%d%d%d", &n, &s, &ms);
    a.rs(n);
    F(i, 0, n)
        scanf("%d", &a[i]);
    root = build(0, n);
    F(g, 0, 2){
        st[g].rs(n);
        F(len, 0, 20){
            F(i, 0, n){
                if(len == 0){
                    st[g][i].rs(20);
                    st[g][i][len] = a[i];
                    cont;
                }
                int r = i + (1 << len) - 1;
                if(r >= n)
                    cont;
                int tl = r - (1 << (len - 1)) + 1;
                if(g == 0)
                    st[g][i][len] = min(st[g][i][len - 1], st[g][tl][len - 1]);
                else
                    st[g][i][len] = max(st[g][i][len - 1], st[g][tl][len - 1]);
            }
        }
    }
    int ans = inf + 1;
    upd(root, 0, n, 0, 0);
    F(i, 1, n + 1){
        int l = 1, r = i;
        while(r - l > 1){
            int mid = (l + r) >> 1;
            int d = stget(1, mid - 1, i - 1) - stget(0, mid - 1, i - 1);
            if(d > s){l = mid + 1;}
            else{r = mid;}
        }
        if(stget(1, l - 1, i - 1) - stget(0, l - 1, i - 1) > s){l = r;}
        r = i - ms + 1;
        if(r < l)
            cont;
        int curr;
        curr = get(root, 0, n, l - 1, r - 1) + 1;
        if(i == n){ans = curr;}
        upd(root, 0, n, i, curr);
    }
    if(ans >= inf)
        printf("-1");
    else
        printf("%d", ans);
    ret 0;
}