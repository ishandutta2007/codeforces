#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

const int inf = 1e9;

struct lca_node {
    int val;
    lca_node *l, *r;
    lca_node(){}
    lca_node(int _v){this->val = _v;}
};

vector<list<int> > gr;
vector<int> h;
vector<int> dfs_list;
vector<int> vfpos;
vector<int> cp;
vector<char> used;
int n;
lca_node * lca_root;

lca_node * lca_build(int l, int r){
    if(l == r){
        return new lca_node(dfs_list[l]);
    }
    int mid = (l + r) >> 1;
    lca_node * nnode = new lca_node;
    nnode->l = lca_build(l, mid);
    nnode->r = lca_build(mid + 1, r);
    nnode->val = (h[nnode->l->val] < h[nnode->r->val]) ? nnode->l->val : nnode->r->val;
    return nnode;
}

int lca_get(lca_node * v, int l, int r, int ul, int ur){
    if(ul > ur){return -1;}
    if(ul == l && ur == r){return v->val;}
    int mid = (l + r) >> 1;
    int vl = lca_get(v->l, l, mid, ul, min(ur, mid));
    int vr = lca_get(v->r, mid + 1, r, max(mid + 1, ul), ur);
    if(vl == -1){return vr;}
    if(vr == -1){return vl;}
    return (h[vl] < h[vr])? vl : vr;
}

void lca_dfs(int v, int p = -1){
    dfs_list.push_back(v);
    if(p == -1){h[v] = 0;}
    else{h[v] = h[p] + 1;}
    for(auto i = gr[v].begin(); i != gr[v].end(); i++){
        int to = *i;
        if(to != p){lca_dfs(to, v); dfs_list.push_back(v);}
    }
}

void lca_prepare(){
    lca_dfs(0);
    vfpos.assign(n, -1);
    for(int i = 0; i < dfs_list.size(); i++){
        if(vfpos[dfs_list[i]] == -1){vfpos[dfs_list[i]] = i;}
    }
    lca_root = lca_build(0, dfs_list.size() - 1);
}

int dist(int v, int u){
    if(vfpos[v] > vfpos[u]){swap(v, u);}
    int lca = lca_get(lca_root, 0, dfs_list.size() - 1, vfpos[v], vfpos[u]);
    return h[v] + h[u] - 2 * h[lca];
}

struct centroid {
    int id, layer;
    centroid(){}
    centroid(int _id, int _layer){
        this->id = _id;
        this->layer = _layer;
    }
};

list<pair<centroid, centroid> > el;
vector<int> msz, mpos;
vector<vector<int> > nc;
vector<centroid> cs;
vector<int> sa;
int cr;

int szdfs(int v, int p){
    int total = 1;
    int cm = 0, pos = -1;
    for(auto i = gr[v].begin(); i != gr[v].end(); i++){
        int to = *i;
        if(used[to] || to == p){continue;}
        int curr = szdfs(to, v);
        if(curr > cm){cm = curr; pos = to; total += curr;}
    }
    msz[v] = cm;
    mpos[v] = pos;
    return total;
}

centroid cdfs(int v, int p, const int & maxs, const int & cl){
    if(msz[v] <= maxs){return centroid(v, cl);}
    return cdfs(mpos[v], v, maxs, cl);
}

centroid process_tree(int root, int cl){
    int tsz = szdfs(root, -1);
    int maxs = tsz/2;
    centroid curr = cdfs(root, -1, maxs, cl);
    cs[curr.id] = curr;
    used[curr.id] = true;
    for(auto i = gr[curr.id].begin(); i != gr[curr.id].end(); i++){
        int to = *i;
        if(!used[to]){
            centroid nxt = process_tree(to, cl + 1);
            el.push_back(make_pair(curr, nxt));
            //break;
        }
    }
    return curr;
}

void fill_sa(int v, int cv){
    sa[v] = cv;
    if(cp[v] != -1){fill_sa(cp[v], dist(0, cp[v]));}
}

void decompose(){
    used.assign(n, false);
    process_tree(0, 0);
    cp.assign(n, -1);
    for(auto it = el.begin(); it != el.end(); it++){
        cp[it->second.id] = it->first.id;
        nc[it->first.id].push_back(it->second.id);
    }
    for(int i = 0; i < n; i++){
        if(cp[i] == -1){
            cr = i; break;
        }
    }
    sa.assign(n, inf);
    fill_sa(0, 0);
}

int get_query(int v, int fv){
    int tmp = sa[v];
    int d = 0;
    for(int i = cp[v]; i != -1; i = cp[i]){
        d = dist(i, v);
        tmp = min(tmp, d + sa[i]);
    }
    return tmp;
}

void set_query(int v, int fv){
    sa[v] = min(sa[v], dist(v, fv));
    if(cp[v] != -1){set_query(cp[v], fv);}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    int q;
    cin >> q;
    gr.resize(n);
    used.resize(n);
    cp.resize(n);
    vfpos.resize(n);
    h.resize(n);
    msz.resize(n);
    mpos.resize(n);
    nc.resize(n);
    cs.resize(n);
    sa.resize(n);
    for(int i = 0; i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        v--; u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    lca_prepare();
    decompose();
    /*for(auto it = el.begin(); it != el.end(); it++){
        cout << it->first.id << " " << it->second.id << endl;
    }*/
    for(int i = 0; i < q; i++){
        int t, v;
        cin >> t >> v;
        v--;
        if(t == 1)
            set_query(v, v);
        else
            cout << get_query(v, v) << endl;
    }
    return 0;
}