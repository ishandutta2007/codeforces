#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int n;
int sa[MAXN], ea[MAXN], sb[MAXN], eb[MAXN];

map<int, vector<int> > event;

int solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &sa[i], &ea[i], &sb[i], &eb[i]);
        event[sa[i]].push_back(i);
        event[ea[i] + 1].push_back(-i);
    }
    set<PII> lef, rig;
    for (auto &e : event) {
        auto &pts = e.second;
        for (auto &pt : pts) {
            if (pt > 0) {
                lef.insert(PII(sb[pt], pt));
                rig.insert(PII(eb[pt], pt));
            }
            else {
                lef.erase(PII(sb[-pt], -pt));
                rig.erase(PII(eb[-pt], -pt));
            }
        }
        if (lef.size()) {
            if (lef.rbegin()->first > rig.begin()->first) {
                return 0;
            }
        }
    }

    lef.clear();
    rig.clear();
    event.clear();

    for (int i = 1; i <= n; i++) {
        event[sb[i]].push_back(i);
        event[eb[i] + 1].push_back(-i);
    }
    
    for (auto &e : event) {
        auto &pts = e.second;
        for (auto &pt : pts) {
            if (pt > 0) {
                lef.insert(PII(sa[pt], pt));
                rig.insert(PII(ea[pt], pt));
            }
            else {
                lef.erase(PII(sa[-pt], -pt));
                rig.erase(PII(ea[-pt], -pt));
            }
        }
        if (lef.size()) {
            if (lef.rbegin()->first > rig.begin()->first) {
                return 0;
            }
        }
    }

    return 1;
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        if (solve(i)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}