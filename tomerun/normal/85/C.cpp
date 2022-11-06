#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long ll;

int n,k;
vector<int> parent;
vector<int> lc;
vector<int> rc;
vector<int> val;
vector<int> lmax;
vector<int> rmin;
vector<int> ma;
vector<int> mi;
vector<double> ans;
int root;

struct State{
    int pos;
    int count;
    ll sum;
};

struct Leaf{
    int val;
    double ans;
};

bool operator<(const Leaf& l, const Leaf& r) {
    return l.val < r.val;
}

int main()
{
    scanf("%d", &n);
    parent.assign(n, -1);
    lc.assign(n, -1);
    rc.assign(n, -1);
    val.assign(n, -1);
    lmax.assign(n, -1);
    rmin.assign(n, -1);
    ma.assign(n, -1);
    mi.assign(n, -1);
    for(int i = 0; i < n; ++i) {
        int p,v;
        scanf("%d %d", &p, &v);
        if (p != -1) {
            --p;
        }
        parent[i] = p;
        val[i] = v;
        if (p != -1) {
            if(lc[p] != -1) {
                rc[p] = i;
            }else{
                lc[p] = i;
            }
        }else{
            root = i;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(rc[i] != -1 && val[lc[i]] > val[rc[i]]) {
            swap(lc[i], rc[i]);
        }
    }
    vector<int> stack;
    stack.push_back(root);
    while(!stack.empty()){
        int cur = stack.back();
        if(lc[cur] == -1) {
            ma[cur] = mi[cur] = rmin[cur] = lmax[cur] = val[cur];
            stack.pop_back();
            continue;
        }
        if(lmax[lc[cur]] != -1) {
            mi[cur] = mi[lc[cur]];
            ma[cur] = ma[rc[cur]];
            lmax[cur] = ma[lc[cur]];
            rmin[cur] = mi[rc[cur]];
            stack.pop_back();
            continue;
        }
        stack.push_back(lc[cur]);
        stack.push_back(rc[cur]);
    }
    ans.assign(n, 0);

    vector<State> st;
    State start = {root, 0, 0};
    st.push_back(start);
    while(!st.empty()){
        State cur = st.back();
        st.pop_back();
        if(lc[cur.pos] == -1) {
            ans[cur.pos] = 1. * cur.sum / cur.count;
            continue;
        }
        State left = {lc[cur.pos], cur.count + 1, cur.sum + rmin[cur.pos]};
        st.push_back(left);
        State right = {rc[cur.pos], cur.count + 1, cur.sum + lmax[cur.pos]};
        st.push_back(right);
    }

    vector<int> inner;
    vector<Leaf> leafs;
    for(int i = 0; i < n; ++i) {
        if(lc[i] == -1) {
            Leaf leaf = {val[i], ans[i]};
            leafs.push_back(leaf);
        }else{
            inner.push_back(val[i]);
        }
    }
    sort(leafs.begin(), leafs.end());
    sort(inner.begin(), inner.end());

    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int q;
        scanf("%d", &q);
        int pos = upper_bound(inner.begin(), inner.end(), q) - inner.begin();
        printf("%.9f\n", leafs[pos].ans);
    }

    return 0;
}