#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, INF = 1e9;

set<int> se[3];

int getm(int idx) {
    if (idx==0) {
        return *(--se[0].end());
    }
    return *(se[2].begin());
}

void add(int v) {
    if (v<getm(0)) {
        se[0].insert(v);
    }
    else if (v>getm(2)) {
        se[2].insert(v);
    }
    else se[1].insert(v);
}

bool flag = 0;
int res = 1;
ll MOD = 1e9+7;
void acc(int v) {
    flag = 1;
    if (v==getm(0)) {
        se[0].erase(--se[0].end());
        auto it = se[1].begin();
        while(it!=se[1].end()) {
            se[2].insert(*it);
            it++;
        }
        se[1].clear();
        return;
    }
    if (v==getm(2)) {
        se[2].erase(se[2].begin());
        auto it = se[1].begin();
        while(it!=se[1].end()) {
            se[0].insert(*it);
            it++;
        }
        se[1].clear();
        return;
    }
    if (getm(0)<v&&v<getm(2)) {
        if (se[1].find(v)!=se[1].end()) {
            auto it = se[1].find(v);
            auto pit = se[1].begin();
            while(pit!=it) {
                se[0].insert(*pit);
                pit++;
            }
            pit = ++it;
            --it;
            while(pit!=se[1].end()) {
                se[2].insert(*pit);
                pit++;
            }
            se[1].clear();
            res = res*2%MOD;
        }
        return;
    }
    res = 0;
}

char str[20];
void inp() {
    int i;
    scanf(" %s",str);
    scanf("%d",&i);
    if (str[1]=='D') add(i);
    else acc(i);
    /*
    auto it = se[0].begin();
    while(it!=se[0].end()) {
        printf("%d ",*it);
        it++;
    }
    printf("\n");
    it = se[1].begin();
    while(it!=se[1].end()) {
        printf("%d ",*it);
        it++;
    }
    printf("\n");
    it = se[2].begin();
    while(it!=se[2].end()) {
        printf("%d ",*it);
        it++;
    }
    printf("\n");
    */
}

int main() {
    scanf("%d",&n);
    se[0].insert(-INF);
    se[2].insert(INF);
    for (int i=0;i<n;i++) inp();
    printf("%lld\n",1LL*res*((int)se[1].size()+1)%MOD);

    return 0;
}