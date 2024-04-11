#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

template<class T, class Cmp = less<T>>
using ordered_set = tree<
    T, null_type, Cmp, rb_tree_tag,
    tree_order_statistics_node_update
>;

int n;
ordered_set<int> rocks, papers, scissors;

ordered_set<int>& getSet(char type) {
    if (type == 'R') return rocks;
    if (type == 'P') return papers;
    return scissors;
}

int solve(const ordered_set<int>& zero, const ordered_set<int>& one, const ordered_set<int>& two) {
    int begin1 = (two.empty() ? n : *two.begin());
    int end1 = (one.empty() ? n : *one.begin());
    int begin2 = (one.empty() ? 0 : *one.rbegin()+1);
    int end2 = (two.empty() ? 0 : *two.rbegin()+1);

    end1 = max(begin1, end1);
    end2 = max(begin2, end2);

    if (begin1 > begin2) {
        swap(begin1, begin2);
        swap(end1, end2);
    }

    if (begin2 <= end1) {
        int begin = begin1, end = max(end1, end2);
        return int(zero.order_of_key(end) - zero.order_of_key(begin));
    }

    return int(zero.order_of_key(end1) - zero.order_of_key(begin1) + zero.order_of_key(end2) - zero.order_of_key(begin2));
}

int answer() {
    return n - solve(papers, rocks, scissors) - solve(rocks, scissors, papers) - solve(scissors, papers, rocks);
}

void run() {
    int q; cin >> n >> q;
    string str; cin >> str;

    rep(i, 0, n) getSet(str[i]).insert(i);
    cout << answer() << '\n';

    while (q--) {
        int i; cin >> i >> str;
        i--;
        rocks.erase(i);
        papers.erase(i);
        scissors.erase(i);
        getSet(str[0]).insert(i);
        cout << answer() << '\n';
    }
}