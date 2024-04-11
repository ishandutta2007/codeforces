#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 1000000;
int n, t[4*MAXN];
void build (int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
    }
}

void update (int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] += add;
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}

int get (int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get (v*2, tl, tm, pos);
    else
        return t[v] + get (v*2+1, tm+1, tr, pos);
}


struct item {
    int prior, cnt;
    int pos;
    int was;
    ll key;
    item * l, * r;
    item() : l(nullptr), r(nullptr), cnt(0) { }
    item (int key, int prior) : key(key), prior(prior), l(nullptr), r(nullptr), cnt(0){ }
};
typedef item * pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}


//void push (pitem it) {
//    if (it && it->add) {
//        if (it->l)  it->l->add = it->add;
//        if (it->r)  it->r->add = it->add;
//        it->add = 0;
//    }
//}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

void upd_all (pitem t) {
    upd_cnt(t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior /*|| (l->prior == r->prior && rand()%2)*/)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_all (t);
}

void split (pitem t, pitem & l, pitem & r, ll key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    // int cur_key = add + cnt(t->l);
    if (key < t->key )//|| (key==t->key && rand()%2))
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add),  l = t;
    upd_all (t);
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior /*|| (it->prior == t->prior && rand()%2)*/)
        split (t, it->l, it->r, it->key),  t = it;
    else {
        //if (it->key == t->key && rand() % 2) insert(t->l, it);
        //else
            insert (it->key < t->key ? t->l : t->r, it);
    }
    upd_all (t);
}

void erase (pitem & t, ll key) {
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
    upd_all (t);
}

//pitem unite (pitem l, pitem r) {
//    if (!l || !r)  return l ? l : r;
//    if (l->prior < r->prior)  swap (l, r);
//    pitem lt, rt;
//    split (r, lt, rt, l->key);
//    l->l = unite (l->l, lt);
//    l->r = unite (l->r, rt);
//    return l;
//}

//void add (pitem t, int l, int r) {
//    pitem t1, t2, t3;
//    split (t, t1, t2, l);
//    split (t2, t2, t3, r-l+1);
//    t2->rev ^= true;
//    merge (t, t1, t2);
//    merge (t, t, t3);
//}

pitem search (pitem t, ll key) {
    if(t==nullptr) return nullptr;
    if (t->key < key) {
        t->r->pos = t->pos + 1;
        if(t->l != nullptr) t->r->pos += t->l->cnt;
        return search(t->r, key);
    }
    else if (t->key > key) {
        t->l->pos = t->pos;
        return search(t->l, key);
    }
    else {
        if(t->l != nullptr) t->pos += t->l->cnt;
        return t;
    }
}

int dp;
pitem find_ind(pitem t, int ind) {
    if(ind < cnt(t->l)) {
        dp++;
        return find_ind(t->l, ind);
    }
    else if(ind > cnt(t->l)) {
        dp++;
        return find_ind(t->r, ind - cnt(t->l) - 1);
    }
    else return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    
    scanf("%d %d", &n, &m);
    vi ans(n,-1);
    vi a(n);
    forn(i,0,n) a[i]=i;
    build(a.data(),1,0,n-1);
    int pr = 0;
    vi where(n,-1);
    int cur = 0;
    std::vector<int> prior;
    for (int i=0; i<n; ++i) prior.push_back(i);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(all(prior), g);
    vector<item> items(n);
    vi p(n,0);
    pitem root(nullptr);
    forn(i,0,n) {
        items[i].key = i+1;
        items[i].was = i;
        items[i].prior = rand();//prior[i];
        items[i].cnt = 0;
        insert(root, &items[i]);
    }
    
    forn(i,0,m) {
        
        int x,y;
        scanf("%d %d", &x, &y);
        x--; y--;
        dp = 1;
        pitem r = find_ind(root, y);
//        if(m>0) {
//            if(i%1 == 0) cout<<i << " dp " << dp <<endl;
//            if(i==4000) return 0;
//        }
        if (where[x] >= 0 || ans[r->was] >= 0) {
            if (where[x] != r->was || x != ans[r->was]) {
                cout<<-1;
                return 0;
            }
        }
        else {
            where[x] = r->was;
            ans[r->was] = x;
            p[x] = r->key;
        }
        int u = r->was;
        erase(root, p[x]);
        p[x] = -cur;
        cur++;
        items[u].cnt = 0;
        //items[u].prior = prior[cur];
        //items[u].prior = rand() % (n);
        items[u].key = p[x];
        items[u].l = nullptr;
        items[u].r = nullptr;
        insert(root, &items[u]);
        
//        if(y>=pr) {
//            
//            // ne trogali
//            if(where[x] >= 0) {
//                cout<<-1;
//                return 0;
//            }
//            int st = get(1,0,n-1,y);
//            ans[st] = x;
//            where[x] = st;
//            p[x] = -cur;
//            items[x].prior = prior[cur];
//            items[x].key=p[x];
//            items[x].cnt = 0;
//            insert(root, &items[x]);
//            cur++;
//            pr++;
//            update (1, 0, n-1, pr, y, -1);
//        }
//        else {
//            if(where[x]==-1) {
//                cout<<-1;
//                return 0;
//            }
//            root->pos = 0;
//            pitem test = search(root, p[x]);
//            if(test==nullptr) {
//                cout<<"I AM KILL";
//                return 0;
//            }
//            if(test->pos != y) {
//                cout<<-1;
//                return 0;
//            }
//            erase(root, p[x]);
//            p[x] = -cur;
//            items[x].cnt = 0;
//            items[x].prior = prior[cur];
//            items[x].key=p[x];
//            items[x].l = nullptr;
//            items[x].r = nullptr;
//            insert(root, &items[x]);
//            cur++;
//        }
    }
    vi free;
    forn(i,0,n) if(where[i]==-1) free.pb(i);
    int pc = 0;
    forn(i,0,n) {
        if(ans[i] == -1) {
            ans[i] = free[pc];
            pc++;
        }
    }
    forn(i,0,n) printf("%d ", 1+ans[i]);
    
}